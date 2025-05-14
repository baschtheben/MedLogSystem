// subclass of medication 

#include "medication.h"

class Pill : public Medication{

    public: 
        Pill(); 
    
        Pill(string Name, string Dosage, int Freq, bool Status);  
    
        virtual void display()const override;
        virtual string getType()const override;
    
    
    };
        