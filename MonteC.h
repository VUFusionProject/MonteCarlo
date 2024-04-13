//
// Created by chaha on 4/12/2024.
//

#ifndef MONTECARLO_MONTEC_H
#define MONTECARLO_MONTEC_H


#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4Material.hh"
#include <G4SystemOfUnits.hh>

class MonteCarloSimulation {
public:
    MonteCarloSimulation();
    ~MonteCarloSimulation();

    void DefineMaterials();
    void SetupSimulation();
    void RunSimulation(int numberOfEvents);

private:
    G4VUserPrimaryGeneratorAction* fPrimaryGeneratorAction;
    G4ParticleGun* fParticleGun;
    G4Material* fStainlessSteel;
    G4Material* fTungsten;
    G4Material* fDeuterium;
};

#endif //MONTECARLO_MONTEC_H
