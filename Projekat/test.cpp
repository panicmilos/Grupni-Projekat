std::vector<int> v{ 5, 9, 3, 7 };
MergeSort::merge_sort<int>(v, &comp);
for (int i = 0; i <= 4; ++i) {
	printf("%d", v[i]);
}


bool comp(int i, int j) {
	return i > j;
}
