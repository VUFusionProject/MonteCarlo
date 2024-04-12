import pyne
from pyne import material
from pyne import mcnp
import numpy as np
from pyne import source_sampling
import matplotlib.pyplot as plt

import matplotlib.pyplot as plt

# Define materials using PyNE
stainless_steel = material.Material({'Fe': 0.7, 'Cr': 0.2, 'Ni': 0.1}, density=7.9)  # Example density
tungsten = material.Material({'W': 1.0}, density=19.25)
deuterium = material.Material({'D': 2}, density=0.00016)  # g/cm^3 for gaseous deuterium at STP

# Configure the source - a 50kV Deuterium-Deuterium reaction
source_energy = 50 * 1e3 * 1.60218e-13  # Convert keV to MeV which is often used in MC simulations

class DDNeutronSource(source_sampling.SourceParticle):
    def __init__(self):
        super(DDNeutronSource, self).__init__()
        self.energy = source_energy  # Set source particle energy

    def sample_particle(self):
        particle = source_sampling.SourceParticle()
        particle.primary = True
        particle.position = np.array([0, 0, 0])  # Assume point source at origin
        particle.energy = self.energy
        particle.dir = np.random.uniform(-1, 1, 3)  # Isotropic emission
        particle.dir /= np.linalg.norm(particle.dir)  # Normalize direction vector
        return particle

# Instantiate the neutron source
neutron_source = DDNeutronSource()

# Placeholder function for Monte Carlo simulation
def runMonteCarlo(materials, geometry, source, num_particles):
    # This function would interact with MCNP or another transport code
    # Simulation results are mocked here for demonstration
    dummy_flux = np.random.rand(100)  # Random flux values
    dummy_energy = np.linspace(0, 10, 100)  # Energy from 0 to 10 MeV
    return {'neutron_flux': dummy_flux, 'energy_spectrum': dummy_energy}

# Run the Monte Carlo simulation
results = runMonteCarlo(materials=[stainless_steel, tungsten, deuterium],
                        geometry="simplified_reactor_model",
                        source=neutron_source,
                        num_particles=10000)

# Analyze and plot the results
flux = results['neutron_flux']
energy = results['energy_spectrum']

plt.figure()
plt.plot(energy, flux)
plt.xlabel('Energy (MeV)')
plt.ylabel('Neutron Flux')
plt.title('Neutron Flux vs. Energy')
plt.grid(True)
plt.show()

# Additional analysis and safety assessments would follow here
