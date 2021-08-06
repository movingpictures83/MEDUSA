# MEDUSA
# Language: C++
# Input: TXT
# Output: DIR
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: MEDUSA 1.6


PluMA plugin to perform genome scaffolding with MEDUSA (Bosi et al, 2015)

The plugin accepts as input a tab-delimited TXT file of keyword-value pairs.
Keywords:
fastafile: Input fasta file
random: Number of iterations
reference: Directory with reference genomes

Output scaffolds will be generated in the user-specified output directory.
