# Construction of binary wavelet tree using RRR structure.

Project repository for [Bioinformatics](http://www.fer.unizg.hr/predmet/bio) course held at Faculty of Electrical Engineering and Computing, University of Zagreb.

## Title

Construction of binary wavelet tree using RRR structure.

## Team members

* Jure Čular, 0036479001
* Bartol Freškura, 0036480392
* Filip Gulan, 0036479428

## Repository contents

* _doc_ directory contains the project documentation sources. Check _documentation.pdf_ file for more details about the project and measurement results
* _src_ directory contains C++ source code of the project
* _tests_ directory contains unit tests and measurements tests
* Branch [feature/packing-unpacking-sequence](https://github.com/fgulan/bioinformatics-project/tree/feature/packing-unpacking-sequence) contains coded RRR sequence as described in documentation

## Compiling

* Position working directory in the root folder of project.
* Run commands:
    ```bash
    $ cmake CMakeLists.txt 
    $ cmake --build ./ --target bioinformatics_project
    ```
    This command will compile the project to a `bioinformatics_project` executable file in the root folder of project.

## Run instructions

Program expects 3 arguments:

1. filename of the sequence in FASTA format
2. filename of the commands file to be executed
3. filename of the output file.

For running given example:

```bash
./bioinformatics_project example/ecoli_seq.txt example/ecoli_commands.txt example/ecoli_outs.txt > example/ecoli_stats.txt
```
