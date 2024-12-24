// beginning of a cat genetics simulator thing. has a vector to store a cat's genetic code in and a method for intepreting allele pairs
// into a code signifying what they express, but not much else.

#include <iostream>
#include <cmath>
#include <vector>

// vector to store genes. first dimension = the locus, second dimension = member of pair
std::vector<std::vector<double>> catGenes(5,std::vector<double>(2));

double interpretAllelePair(double allele1,double allele2);

int main()
{
    int x = 2;
    
    catGenes[x][1] = 2;
    catGenes[x][2] = 1.1;
    
    std::cout<<interpretAllelePair(catGenes[x][1],catGenes[x][2]);
    return 0;
}


// interpet allele pair into id representing which allele is dominant + any codominance
double interpretAllelePair(double allele1,double allele2)
{
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
    
    // prints the dominant and recessive allele
    std::cout<<" dominant allele " << dominantAllele <<"\n recessive allele " << recessiveAllele <<"\n";
    
    
    // checking for codominant recessive allele + compatibility with dominant
    if (recessiveAllele > round(recessiveAllele) && (dominantAllele - round(recessiveAllele)) < 1.9) {
        std::cout<<"\n codominant ";
        return (round(dominantAllele) + round(recessiveAllele))/2;
    } else {
        return dominantAllele;
    }
    
}
