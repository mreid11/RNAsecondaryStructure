#include <stdio.h>
#include <stdlib.h>

int main(char argc, char* argv[]){
	if(argc < 2){
		printf("Please supply one argument for Shape Type\n");
	} else {
		system("echo \"AGAUUCUGCGUCUGUAUGUGAGUUGUAUGAUGCUGUAGUCUGCAUGUCA\" | Kinfold > output.txt\n");
		system("javac RunShapeOnPathway.java MakeShape.java");
		char buf[256];
		snprintf(buf, sizeof buf, "java RunShapeOnPathway %s", argv[1]);
		system(buf);
	}
}
