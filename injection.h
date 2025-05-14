//subclass of medication

#include "medication.h"

class Injection : public Medication{

    public:
        Injection();
    
        Injection(string Name, string Dosage, int Freq, bool Status);
    
        virtual void display() const override;
        virtual string getType()const override;
    
};      