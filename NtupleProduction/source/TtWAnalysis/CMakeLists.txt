atlas_subdir( Wtt None )

# Generate a CINT dictionary source file:
atlas_add_root_dictionary( Wtt _cintDictSource
                           ROOT_HEADERS Root/LinkDef.h
                           EXTERNAL_PACKAGES ROOT )

# Build a library that other components can link against:
atlas_add_library( Wtt Root/*.cxx Root/*.h Root/*.icc
                   Wtt/*.h Wtt/*.icc Wtt/*/*.h
                   Wtt/*/*.icc ${_cintDictSource} 
                   PUBLIC_HEADERS Wtt
                   LINK_LIBRARIES TopObjectSelectionTools
                                  TopEventSelectionTools
                                  TopEvent
                                  TopConfiguration
                                  TopAnalysis
                                  JetAnalysisInterfacesLib
                                  AsgTools
                                  ${ROOT_LIBRARIES}
                   INCLUDE_DIRS ${ROOT_INCLUDE_DIRS} )
