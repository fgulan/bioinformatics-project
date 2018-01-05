#include <iostream>
#include <fstream>
#include <numeric>
#include "utility/bioinf_utility.h"
#include "wavelet/WaveletTree.h"

static std::string const k_rank_key = "rank";
static std::string const k_select_key = "select";
static std::string const k_access_key = "access";

void measure_rank(std::string command, WaveletTree& tree, std::vector<measured_time_t>& times, std::string& output);
void measure_select(std::string command, WaveletTree& tree, std::vector<measured_time_t>& times, std::string& output);
void measure_access(std::string command, WaveletTree& tree, std::vector<measured_time_t>& times, std::string& output);

int main(int argc, char *argv[])
{
    if (argc != 4) {
        std::cout << "Invalid number of arguments!" << std::endl;
        std::cout << "1. filename of the sequence file" << std::endl;
        std::cout << "2. filename of the commands file" << std::endl;
        std::cout << "3. filename of the output file" << std::endl;
        return EXIT_FAILURE;
    }

    measured_time_t tree_creation_time_micro;
    measured_memory_t tree_memory_kb;
    std::vector<measured_time_t> rank_times_nano;
    std::vector<measured_time_t> select_times_nano;
    std::vector<measured_time_t> access_times_nano;

    // Read input file
    std::string sequence = read_fasta_file(argv[1]);

    // Create tree and measure its statistics
    auto start_tree_time = std::chrono::high_resolution_clock::now();
    auto start_memory = get_current_memory();
    auto tree = WaveletTree(sequence);
    auto end_memory = get_current_memory();
    auto end_tree_time = std::chrono::high_resolution_clock::now();

    // Calculate tree time and memory usage
    tree_creation_time_micro = std::chrono::duration_cast<std::chrono::microseconds>(end_tree_time - start_tree_time).count();
    tree_memory_kb = (end_memory - start_memory) / 1024;

    std::ifstream commands(argv[2]);
    std::string output;
    std::string command;
    while (std::getline(commands, command)) {
        if (command.find(k_rank_key) == 0) {
            measure_rank(command, tree, rank_times_nano, output);
        } else if (command.find(k_select_key) == 0) {
            measure_select(command, tree, select_times_nano, output);
        } else if (command.find(k_access_key) == 0) {
            measure_access(command, tree, access_times_nano, output);
        }
    }

    auto average = [](std::vector<measured_time_t > const& v) {
        return std::accumulate(v.begin(), v.end(), .0) / v.size();
    };

    std::string statistics;
    auto rank_avrg_nano = average(rank_times_nano);
    auto select_avrg_nano = average(select_times_nano);
    auto access_avrg_nano = average(access_times_nano);
    statistics += "Tree memory consumption (kB): " + std::to_string(tree_memory_kb) + "\n";
    statistics += "Tree creation time (us): " + std::to_string(tree_creation_time_micro) + "\n";
    statistics += "Average rank time (ns): " + std::to_string(rank_avrg_nano) + "\n";
    statistics += "Average select time (ns): " + std::to_string(select_avrg_nano) + "\n";
    statistics += "Average access time (ns): " + std::to_string(access_avrg_nano) + "\n";
    output += statistics;

    std::ofstream output_stream(argv[3]);
    output_stream << output;
    std::cout << statistics;
    return EXIT_SUCCESS;
}

void measure_rank(std::string command, WaveletTree& tree, std::vector<measured_time_t>& times, std::string& output)
{
    char_t symbol;
    size_t index;
    auto parse_command = k_rank_key + " %c %zu";
    sscanf(command.c_str(), parse_command.c_str(), &symbol, &index);

    auto start_time = std::chrono::high_resolution_clock::now();
    auto result = tree.rank(symbol, index);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    times.push_back(elapsed_time);
    output += command + " => " + std::to_string(result) + "\n";
}

void measure_select(std::string command, WaveletTree& tree, std::vector<measured_time_t>& times, std::string& output)
{
    char_t symbol;
    size_t count;
    auto parse_command = k_select_key + " %c %zu";
    sscanf(command.c_str(), parse_command.c_str(), &symbol, &count);

    auto start_time = std::chrono::high_resolution_clock::now();
    auto result = tree.select(symbol, count);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    times.push_back(elapsed_time);
    output += command + " => " + std::to_string(result) + "\n";
}

void measure_access(std::string command, WaveletTree& tree, std::vector<measured_time_t>& times, std::string& output)
{
    size_t index;
    auto parse_command = k_access_key + " %zu";
    sscanf(command.c_str(), parse_command.c_str(), &index);

    auto start_time = std::chrono::high_resolution_clock::now();
    auto result = tree.access(index);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    times.push_back(elapsed_time);
    output += command + " => " + std::to_string(result) + "\n";
}
