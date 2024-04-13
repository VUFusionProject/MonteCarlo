// main.cpp
#include "MonteC.h"
#include "G4RunManager.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"

MonteCarloSimulation::MonteCarloSimulation() {
    fParticleGun = new G4ParticleGun(1);
}

MonteCarloSimulation::~MonteCarloSimulation() {
    delete fParticleGun;
}

void MonteCarloSimulation::DefineMaterials() {
    // Use Geant4's G4NistManager to define materials
    G4NistManager* nistManager = G4NistManager::Instance();

    // Define materials
    fStainlessSteel = nistManager->FindOrBuildMaterial("G4_STAINLESS-STEEL");
    fTungsten = nistManager->FindOrBuildMaterial("G4_W");
    fDeuterium = nistManager->FindOrBuildMaterial("G4_DEUTERIUM_GAS");
}

void MonteCarloSimulation::SetupSimulation() {
    // Setup the default particle kinematic
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName = "neutron";
    G4ParticleDefinition* particle = particleTable->FindParticle(particleName);

    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
    fParticleGun->SetParticleEnergy(50.*keV);
}

void MonteCarloSimulation::RunSimulation(int numberOfEvents) {
    // Create run manager
    G4RunManager* runManager = new G4RunManager;

    // Initialize the Geant4 kernel
    runManager->Initialize();

    // Start a run
    runManager->BeamOn(numberOfEvents);

    delete runManager;
}

int main() {
    MonteCarloSimulation simulation;

    simulation.DefineMaterials();
    simulation.SetupSimulation();
    simulation.RunSimulation(3);

    return 0;
}
