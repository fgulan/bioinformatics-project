# Construction of binary wavelet tree using RRR structure.

Project repository for [Bioinformatics](http://www.fer.unizg.hr/predmet/bio) course held at Faculty of Electrical Engineering and Computing, University of Zagreb.

## Title

Construction of binary wavelet tree using RRR structure.

## Team members

Jure Čular, 0036479001  
Bartol Freškura, 0036480392
Filip Gulan, 0036479428

## Repository contents

* _doc_ directory contains the project documentation sources. Check _documentation.pdf_ file for more details about the project and measurement results
* _src_ directory contains C++ source code of the project
* _tests_ directory contains unit tests measurment tests 

## Compiling

* Position terminal working directory in the root folder of project.
* Run command:
    ```bash
    cmake --build cmake-build-release/ --target bioinformatics_project
    ```
    This command will compile the project to a `bioinformatics_project` executable file inside `cmake-build-release` folder.

## Run instructions

Program expects 3 arugments:

1. filename of the sequence in FASTA format
2. filename of the commands file to be executed
3. filename of the output file.

For running given example:

```bash
./cmake-build-release/bioinformatics_project example/ecoli_seq.txt example/ecoli_commands.txt example/ecoli_outs.txt > example/ecoli_stats.txt
```
