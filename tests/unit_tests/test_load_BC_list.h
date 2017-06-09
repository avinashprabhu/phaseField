// Unit test(s) for the method "parse_line"

template <int dim,typename T>
  bool unitTest<dim,T>::test_load_BC_list(){
  	bool pass = false;

    char buffer[100];

	std::cout << "\nTesting 'load_BC_list'... " << std::endl;

	//create test problem class object
    dealii::ParameterHandler parameter_handler;
    userInputParameters<2> userInputs;

    // 2D test:
    std::vector<std::string> list_of_BCs;
    list_of_BCs.push_back("DIRICHLET: 2.5");
    list_of_BCs.push_back("PERIODIC,PERIODIC,ZERO_DERIVATIVE,ZERO_DERIVATIVE");
    list_of_BCs.push_back("DIRICHLET: 2.5,DIRICHLET: 1.5,ZERO_DERIVATIVE,ZERO_DERIVATIVE");

    userInputs.load_BC_list(list_of_BCs, userInputs.BC_list);

    bool pass1;
    pass1 = userInputs.BC_list.size() == 3;
    pass1 = pass1 && (userInputs.BC_list[0].var_BC_type.size() == 4);
    for (unsigned int i=0; i<userInputs.BC_list[0].var_BC_type.size(); i++){
        pass1 = pass1 && (userInputs.BC_list[0].var_BC_type[i] == DIRICHLET);
        pass1 = pass1 && (userInputs.BC_list[0].var_BC_val[i] == 2.5);
    }
    sprintf (buffer, "Subtest 1 result for 'load_BC_list': %u\n", pass1);
    std::cout << buffer;

    bool pass2;
    pass2 = (userInputs.BC_list[1].var_BC_type[0] == PERIODIC);
    pass2 = pass2 && (userInputs.BC_list[1].var_BC_type[1] == PERIODIC);
    pass2 = pass2 && (userInputs.BC_list[1].var_BC_type[2] == ZERO_DERIVATIVE);
    pass2 = pass2 && (userInputs.BC_list[1].var_BC_type[3] == ZERO_DERIVATIVE);
    sprintf (buffer, "Subtest 2 result for 'load_BC_list': %u\n", pass2);
    std::cout << buffer;

    bool pass3;
    pass3 = (userInputs.BC_list[2].var_BC_type[0] == DIRICHLET);
    pass3 = pass3 && (userInputs.BC_list[2].var_BC_val[0] == 2.5);
    pass3 = pass3 && (userInputs.BC_list[2].var_BC_type[1] == DIRICHLET);
    pass3 = pass3 && (userInputs.BC_list[2].var_BC_val[1] == 1.5);
    pass3 = pass3 && (userInputs.BC_list[2].var_BC_type[2] == ZERO_DERIVATIVE);
    pass3 = pass3 && (userInputs.BC_list[2].var_BC_type[3] == ZERO_DERIVATIVE);
    sprintf (buffer, "Subtest 3 result for 'load_BC_list': %u\n", pass3);
    std::cout << buffer;

    // 3D test:
    list_of_BCs.clear();
    userInputParameters<3> userInputs_3D;
    list_of_BCs.push_back("DIRICHLET: 2.5");
    list_of_BCs.push_back("PERIODIC,PERIODIC,ZERO_DERIVATIVE,ZERO_DERIVATIVE,PERIODIC,PERIODIC");

    userInputs_3D.load_BC_list(list_of_BCs, userInputs_3D.BC_list);
    bool pass4;
    pass4 = userInputs_3D.BC_list.size() == 2;
    pass4 = pass4 && (userInputs_3D.BC_list[0].var_BC_type.size() == 6);
    for (unsigned int i=0; i<userInputs_3D.BC_list[0].var_BC_type.size(); i++){
        pass4 = pass4 && (userInputs_3D.BC_list[0].var_BC_type[i] == DIRICHLET);
        pass4 = pass4 && (userInputs_3D.BC_list[0].var_BC_val[i] == 2.5);
    }
    sprintf (buffer, "Subtest 4 result for 'load_BC_list': %u\n", pass4);
    std::cout << buffer;

    bool pass5;
    pass5 = (userInputs_3D.BC_list[1].var_BC_type[0] == PERIODIC);
    pass5 = pass5 && (userInputs_3D.BC_list[1].var_BC_type[1] == PERIODIC);
    pass5 = pass5 && (userInputs_3D.BC_list[1].var_BC_type[2] == ZERO_DERIVATIVE);
    pass5 = pass5 && (userInputs_3D.BC_list[1].var_BC_type[3] == ZERO_DERIVATIVE);
    pass5 = pass5 && (userInputs_3D.BC_list[1].var_BC_type[4] == PERIODIC);
    pass5 = pass5 && (userInputs_3D.BC_list[1].var_BC_type[5] == PERIODIC);
    sprintf (buffer, "Subtest 5 result for 'load_BC_list': %u\n", pass5);
    std::cout << buffer;


    pass = pass1 && pass2 && pass3 && pass4 && pass5;

	sprintf (buffer, "Test result for 'load_BC_list': %u\n", pass);
	std::cout << buffer;

	return pass;
}