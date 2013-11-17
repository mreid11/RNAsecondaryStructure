#include <stdio.h>
#include <stdlib.h>

int main(char argc, char* argv[]){
	if(argc < 2){
		printf("Incorrect usage: .a.out [shape number] [input filename molecule1] [output filename molecule1] [input filename molecule2] [output filename molecule2]\n");
	} else {
		FILE *f=fopen("FinalAlignment.txt", "r");
		fclose(f);
//		if(_access("FinalAlignment.txt",0) ==-1){
//			printf("HI");
			system("rm FinalAlignment.txt");
//		}
		//IF FILE "FINAL ALIGNMENT" EXISTS DELETE IT
		char buffone[256];
		snprintf(buffone, sizeof buffone, "echo \"AGAUUCUGCGUCUGUAUGUGAGUUGUAUGAUGCUGUAGUCUGCAUGUCA\" | Kinfold > %s\n", argv[2]);
		system(buffone);
		system("javac RunShapeOnPathway.java MakeShape.java");
		char buf[256];
		snprintf(buf, sizeof buf, "java RunShapeOnPathway %s %s %s", argv[1], argv[2], argv[3]);
		system(buf);



		char bufftwo[256];
		snprintf(bufftwo, sizeof bufftwo, "echo \"AGAUUCUGCGUCUGUAUGUGAGUUGUAUGAUGCUGUAGUCUGCAUGUCA\" | Kinfold > %s\n", argv[4]);
		system(bufftwo);
		system("javac RunShapeOnPathway.java MakeShape.java");
		char buffthree[256];
		snprintf(buffthree, sizeof buffthree, "java RunShapeOnPathway %s %s %s", argv[1], argv[4], argv[5]);
		system(buffthree);

		system("javac TwoPathwaysAlign.java AlignPathway.java");
		system("java TwoPathwaysAlign");
	}
}
