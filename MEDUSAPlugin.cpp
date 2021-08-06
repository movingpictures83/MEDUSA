#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "MEDUSAPlugin.h"

void MEDUSAPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
 
}

void MEDUSAPlugin::run() {
   
}

void MEDUSAPlugin::output(std::string file) {
//java -jar medusa.jar -f SPAdes/ -i ./Short.spades.fasta -v -random 5 -o ./03_Scaffolds/
 
   std::string command = "cd plugins/MEDUSA/medusa; java -jar medusa.jar -f ../../../"+std::string(PluginManager::prefix())+"/"+parameters["reference"]+" -i ../../../"+std::string(PluginManager::prefix())+"/"+parameters["fastafile"]+" -v -random "+parameters["random"]+" -o ../../../"+file+"; rm *.delta *.coords; cd ../../../";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<MEDUSAPlugin> MEDUSAPluginProxy = PluginProxy<MEDUSAPlugin>("MEDUSA", PluginManager::getInstance());
