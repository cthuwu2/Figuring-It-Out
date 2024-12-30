// alleles index, random genetic code generator, + allele pair interpretation!

#include <iostream>
#include <cmath>

double allelesIndex[41][5] = {
    // 1, brown mod
        {1, 2, 3},
    // 2, dilution
        {1, 2},
    // 3, dilute mod
        {1, 2},
    // 4, amber
        {1, 2},
    // 5, colorpoint
        {1, 2, 3.1, 4, 5},
    // 6, white
        {1.1, 2, 3},
    // 7, banding
        {1, 2},
    // 8, tabby pattern
        {1, 2},
    // 9, mackeral spotting
        {1.1, 2},
    // 10, bengal mod
        {1, 2},
    // 11, ticked
        {1, 2},
    // 12, ticked mod
        {1, 2},
    // 13, silver inhibitor
        {1, 2},
    // 14, wide band
        {1, 2},
    // 15, wide band mod
        {1.1, 2},
    // 16, melanocyte mod
        {1.1, 2.1, 3},
    // 17, melanocyte activity
        {1.1, 2.1, 3},
    // 18, blue refraction
        {1.1, 2.1, 3},
    // 19, melanin distribution mod
        {1.1, 2},
    // 20, congenital strabismus
        {1, 2, 3, 4},
    // 21, hair length
        {1, 2},
    // 22, hair texture
        {1, 2, 3, 4},
    // 23, long hair mod
        {1, 2.1, 3},
    // 24, sparse hair
        {1, 2},
    // 25, hairlessness mod
        {1.1, 2},
    // 26, body shape
        {1.1, 2.1, 3},
    // 27, metabolism
        {1.1, 2.1, 3},
    // 28, muscle mass gain
        {1.1, 2.1, 3},
    // 29, size potential
        {1.1, 2.1, 3},
    // 30, dwarfism
        {1, 2},
    // 31, ear type
        {1, 2, 3},
    // 32, ear placement
        {1.1, 2.1, 3},
    // 33, ear size
        {1.1, 2.1, 3},
    // 34, face roundness
        {1.1, 2.1, 3},
    // 35, face strength
        {1.1, 2.1, 3},
    // 36, face flattening mod
        {1.1, 2},
    // 37, eye shape
        {1.1, 2.1, 3},
    // 38, eye size
        {1.1, 2.1, 3},
    // 39, tail type
        {1, 2, 3},
    // 40, paw mod
        {1.1, 2.1, 3},
    // 41, malocclusion
        {1, 2, 3},
};


int checkLociMax(int loci);
void generateRandomGeneticCode(double *targetArray);
void copyGeneticCode(double *targetCode, double *copyCode);
void interpretGeneticCode(double *targetCode);
double interpretAllelePair(double allele1,double allele2);

int main()
{
    // Providing a seed value
	srand(time(0));
	
	// makes array to store genetic code and pointer that points to it (testing)
	double geneticCode[123];
	double *geneticCodePointer;
	geneticCodePointer = geneticCode;
	
    generateRandomGeneticCode (geneticCodePointer);
    
    interpretGeneticCode(geneticCodePointer);

    // prints geneticCode
    for (int loci = 0; loci < 41; loci++) {
        
        std::cout<< loci + 1 <<": " << geneticCode[loci] << "," << geneticCode[loci + 41] << " = " << geneticCode[loci + 82] << "\n";
        
    }
    
    return 0;
}

void generateRandomGeneticCode (double *targetArray) {
    
    // *targetArray being a pointer to the array to store the generated genetic code in
    
    // loop that goes through every loci
    for (int loci = 0; loci < 41; loci++) {
        
        // checks for the max of the target loci
        int lociMax = checkLociMax(loci);
        
        // sets each allele in the loci to a random loci from the allelesIndex
        *(targetArray + loci) = allelesIndex[loci][rand() %lociMax];
        *(targetArray + loci + 41) = allelesIndex[loci][rand() %lociMax];
        
    }

}

//checks for the number of valid alleles in a given loci
int checkLociMax(int loci) {
    int lociMax = 5;
    
    for (int i = 0; i < 5; i++) {
        if (allelesIndex[loci][i]==0) {
            lociMax--;
        }
    }
    return lociMax;
}

// copies the contents of one array of genetic code to another array of the correct size
void copyGeneticCode(double *targetCode, double *copyCode) {
    
    // with targetCode being the array to reference and copyCode being the array to be overwritten
    
    for (int i = 0; i < 123; i++) {
        *(targetCode + i) = *(copyCode + i);
    }
}

// interpret each allele pair in the target code and add to "third row" (loci number + 82)
void interpretGeneticCode(double *targetCode) {
    
    for (int i = 0; i < 41; i++) {
        
        *(targetCode + 82 + i) = (interpretAllelePair(*(targetCode + i), *(targetCode + 41 + i)));
    }
}

// interpet allele pair into id representing which allele is dominant + any codominance
double interpretAllelePair(double allele1,double allele2) {
    double dominantAllele;
    double recessiveAllele;
    
    // assigning dominance
    
    if (allele1 > allele2) {
        dominantAllele = allele1;
        recessiveAllele = allele2;
    } else {
        dominantAllele = allele2;
        recessiveAllele = allele1;
    }
    
    // checking for codominant recessive allele + compatibility with dominant
    if (recessiveAllele > round(recessiveAllele) && (dominantAllele - round(recessiveAllele)) < 1.9) {
        
        return (round(dominantAllele) + round(recessiveAllele))/2;
    } else {
        
        return dominantAllele;
    }
    
}
