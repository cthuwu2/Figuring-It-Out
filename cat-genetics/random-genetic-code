// alleles index + random genetic code generator

#include <iostream>

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
void generateRandomGeneticCode ();

int main()
{
    // Providing a seed value
	srand(time(0));
	
    generateRandomGeneticCode ();

    return 0;
}

void generateRandomGeneticCode () {
    
    // array to store genetic code in
    double geneticCode[41][2];
    
    // loop that goes through every loci
    for (int loci = 0; loci < 41; loci++) {
        
        // checks for the max of the target loci
        int lociMax = checkLociMax(loci);
        
        // sets each allele in the loci to a random loci from the allelesIndex
        geneticCode[loci][1] = allelesIndex[loci][rand() %lociMax];
        geneticCode[loci][2] = allelesIndex[loci][rand() %lociMax];
        
    }
    
    // prints full genetic code
    for (int loci = 0; loci < 41; loci++) {
        
        std::cout<< loci + 1 <<": " << geneticCode[loci][1] << "," << geneticCode[loci][2] << "\n";
        
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
