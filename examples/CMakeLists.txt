MACRO(ADD_EXAMPLE arg1)
	ADD_EXECUTABLE(${arg1} ${arg1}.cpp)
	TARGET_LINK_LIBRARIES(${arg1} ${MANDATORY_LIBRARIES})
ENDMACRO(ADD_EXAMPLE)

# Supervised learning examples
ADD_EXAMPLE(supervised_learning_koza_quintic)
ADD_EXAMPLE(supervised_learning_data_set)

# Solving differential equations examples
ADD_EXAMPLE(tsoulos_ode1)
ADD_EXAMPLE(tsoulos_nlode3)

# Finding first integrals examples
ADD_EXAMPLE(hamiltonian_spring_mass)
ADD_EXAMPLE(hamiltonian_spring_mass_lipson)
ADD_EXAMPLE(hamiltonian_kepler)