#include "header.h"

using namespace std;

string translator(string seq, int st, int en) {
    string returnSequence = "MET";

    for(int i=st; i<en; i+=3) {
        string protein = seq.substr(i, 3);

        // there's definitely more efficient methods... but i'm too lazy
        // i'm just a girl ):
        if(seq.substr(i, 2)=="CU") {
            returnSequence+="-LEU";

        } else if(seq.substr(i, 2)=="CC") {
            returnSequence+="-PRO";

        } else if(protein=="CAU" || protein=="CAC") {
            returnSequence+="-HIS";

        } else if(protein=="CAA" || protein=="CAG") {
            returnSequence+="-GLN";

        } else if(seq.substr(i, 2)=="CG") {
            returnSequence+="-ARG";

        } else if(seq.substr(i, 2)=="AU") {
            returnSequence+="-ILE";

        } else if(seq.substr(i, 2)=="AC") {
            returnSequence+="-THR";

        } else if(protein=="AAU" || protein=="AAC") {
            returnSequence+="-ASN";

        } else if(protein=="AAA"||protein=="AAG") {
            returnSequence+="-LYS";
        
        } else if(protein=="AGU"||protein=="AGC") {
            returnSequence+="-SER";

        } else if(protein=="AGA"||protein=="AGG") {
            returnSequence+="-ARG";

        } else if(seq.substr(i, 2)=="GU") {
            returnSequence+="-YAL";

        } else if(seq.substr(i, 2)=="GC") {
            returnSequence+="-ALA";

        } else if(protein=="GAU"||protein=="GAC") {
            returnSequence+="-ASP";

        } else if(protein=="GAA"||protein=="GAG") {
            returnSequence+="-GLU";

        } else if(seq.substr(i, 2)=="GG") {
            returnSequence+="-GLY";

        } else if(protein=="UUU"||protein=="UUC") {
            returnSequence+="-PHE";

        } else if(protein=="UUA"||protein=="UUG") {
            returnSequence+="-LEU";

        } else if(seq.substr(i, 2)=="UC") {
            returnSequence+="-SER";

        } else if(seq.substr(i, 2)=="UA") {
            returnSequence+="-TYR";

        } else if(protein=="UGU"||protein=="UGC") {
            returnSequence+="-CYS";

        } else if(protein=="UGG") {
            returnSequence+="-TRP";

        } else {
            returnSequence+="-???";

        }


    }

    returnSequence+="-STOP";

    return returnSequence;

}

int main() {
    
    cout << "Simple RNA to Protein Translator (Compiler)\n";
    cout << "Enter number of sequences:\n ";
    int nums;
    cin >> nums;

    for(int i=0; i<nums; i++) {
        cout << "Enter sequence:\n ";

        string sequence2;
        cin >> sequence2;

        int startCodon = sequence2.find("AUG");

        int endCodon;

        string sequence = sequence2.substr(startCodon+3);

        if(sequence.find("UAA")!=string::npos) {
            endCodon = sequence.find("UAA");

        } else if(sequence.find("UGA")!=string::npos) {
            endCodon = sequence.find("UGA");

        } else if(sequence.find("UAG")!=string::npos) {
            endCodon = sequence.find("UAG");

        } else {
            endCodon = -1;
            cout << "No end sequence found ):";
            return 0;
        }

        string protein;
        protein = translator(sequence, 0, endCodon);

        cout << "Protein Sequence: " << protein << "\n";
    
    }

    return 0;
}
