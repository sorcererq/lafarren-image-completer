cmake_minimum_required(VERSION 2.6)

project(ImageCompleter)

find_package(wxWidgets COMPONENTS core base REQUIRED)
include( ${wxWidgets_USE_FILE} )

set(cmdsrc src/image-completer-cmd)
set(prioritybp src/priority-bp/impl)
set(tech src/tech)

include_directories(lib/tacus/ src/image-completer-cmd src/priority-bp src/priority-bp/api src/priority-bp/impl src/priority-bp/impl/compositors src/priority-bp/impl/energy-calculators src/tech/tech src/tech)

set(USE_POISSON OFF CACHE BOOL "Use Poisson blending?" FORCE)
set(USE_THREADS OFF CACHE BOOL "Use threads?" FORCE)

###############
set(ImageCompleterSources

${cmdsrc}/CommandLineOptions.cpp
${cmdsrc}/Pch.cpp
${cmdsrc}/SettingsUi.cpp

${prioritybp}/Compositor.cpp
${prioritybp}/ConstNodeLabels.cpp
${prioritybp}/EnergyCalculatorContainer.cpp
${prioritybp}/HostImageLocal.cpp
${prioritybp}/Image.cpp
${prioritybp}/Label.cpp
${prioritybp}/Mask.cpp
${prioritybp}/MaskWritable.cpp
${prioritybp}/NeighborEdge.cpp
${prioritybp}/Node.cpp
${prioritybp}/NodeSet.cpp
${prioritybp}/Pch.cpp
${prioritybp}/PriorityBp.cpp
${prioritybp}/PriorityBpRunner.cpp
${prioritybp}/ScalableDebugging.cpp
${prioritybp}/Settings.cpp

${prioritybp}/compositors/CompositorRoot.cpp
${prioritybp}/compositors/CompositorUtils.cpp
${prioritybp}/compositors/ImageFloat.cpp
${prioritybp}/compositors/OutputBlenderDebugSoftMaskIntensity.cpp
${prioritybp}/compositors/OutputBlenderSoftMask.cpp
${prioritybp}/compositors/PatchBlenderNone.cpp
${prioritybp}/compositors/PatchBlenderPriority.cpp
${prioritybp}/compositors/PatchTypeDebugPatchOrder.cpp
${prioritybp}/compositors/PatchTypeNormal.cpp

${prioritybp}/energy-calculators/EnergyCalculatorFft.cpp
${prioritybp}/energy-calculators/EnergyCalculatorFftUtils.cpp
${prioritybp}/energy-calculators/EnergyCalculatorPerPixel.cpp

${tech}/Pch.cpp
${tech}/tech/CmdLine.cpp
${tech}/tech/ImageUtils.cpp
${tech}/tech/Profile.cpp
${tech}/tech/StrUtils.cpp
${tech}/tech/Time.cpp

)

#if TAUCS is setup correctly, we would want to enable Poisson blending
IF(USE_POISSON)
  set(ImageCompleterSources ${ImageCompleterSources}
  ${prioritybp}/compositors/PatchTypePoisson.cpp
  ${prioritybp}/compositors/PoissonSolver.cpp
  ${prioritybp}/compositors/TaucsMatrix.cpp)
ENDIF(USE_POISSON)

#####################################


add_executable(ImageCompleter ${cmdsrc}/Main.cpp ${ImageCompleterSources})
target_link_libraries(ImageCompleter ${wxWidgets_LIBRARIES})