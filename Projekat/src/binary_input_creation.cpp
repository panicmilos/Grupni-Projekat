//ofstream myfile("./res/input_bin.bin", ios::out | ios::binary);
//
//		student s("dejan", "todorovic", "sw17/2018");
//		std::vector<int> v1 = { 100, 95, 92, 100, 94, 99 };
//		std::vector<int> v2 = { 100, 98, 90, 95 };
//		std::vector<int> v3 = { 70, 100, 88, 80, 100, 92, 96, 100, 89, 93 };
//
//		s.write_to_binary_file(myfile);
//		myfile.write((char*)&v1[0], 6 * sizeof(int));
//		myfile.write((char*)&v2[0], 4 * sizeof(int));
//		myfile.write((char*)&v3[0], 10 * sizeof(int));
//
//		student s1("milos", "panic", "sw19/2018");
//		std::vector<int> v1v1 = { 100, 94, 100, 95, 97, 89 };
//		std::vector<int> v1v2 = { 100, 97, 100, 100 };
//		std::vector<int> v1v3 = { 80, 90, 86, 82, 99, 100, 94, 84, 100, 91 };
//
//		s1.write_to_binary_file(myfile);
//		myfile.write((char*)&v1v1[0], 6 * sizeof(int));
//		myfile.write((char*)&v1v2[0], 4 * sizeof(int));
//		myfile.write((char*)&v1v3[0], 10 * sizeof(int));
//
//		student s2("zoran", "jankov", "sw08/2018");
//		std::vector<int>v12 = { 98, 91, 40, 95, 97, 89 };
//		std::vector<int>v22 = { 64, 97, 81, 100 };
//		std::vector<int>v32 = { 80, 92, 86, 85, 92, 91, 94, 85, 90, 91 };
//
//		s2.write_to_binary_file(myfile);
//		myfile.write((char*)&v12[0], 6 * sizeof(int));
//		myfile.write((char*)&v22[0], 4 * sizeof(int));
//		myfile.write((char*)&v32[0], 10 * sizeof(int));
//
//		myfile.close();
