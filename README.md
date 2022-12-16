# astral-mikado
Project for modeling intracellular actin filament networks

See current status at: https://docs.google.com/document/d/1nozVskqsPu_7O1Xv4FyEvC2nrBnUReEojoOLQpzUOaE/edit?usp=sharing

Summary of code:
  * metropolis_v5.m is the "core" script file, contains calls to functions generateMikadoNetwork.m and metropolisMikado.m
  * Running metropolis_v5 generates one spring (filament) network and finds its equilibrium configuration under the specified force values using the Metropolis-Hastings algorithm
  * Records:
    * netStats.mat file containing information about the generated network and its initial state
    * Entire energy history of network for each force test in a .bin file (large files!)
    * Periodic "frame*.mat" snapshots (interval specified in metropolisMikado.m) of network state for each force test
  * mikadoMovie.m is an auxiliary script file used to visualize the network deformation as the algorithm executes, must manually specify where the network information and state data is
