//char* my_strcat(char* pd, char* ps) {
//	char* po = pd;
//	while (*pd != '\0') {
//		pd++;
//	}
//	while (*ps != '\0') {
//		*pd = *ps;
//		pd++;
//		ps++;
//	}
//	*pd = '\0';
//	return po;
//}
//
//int my_strlen(char* ps) {
//	int cnt = 0;
//	while (*ps != '\0') {
//		cnt++;
//		ps++;
//	}
//	return cnt;
//}
//
//int my_strcmp(char* pa, char* pb) {
//	while ((*pa == *pb) && (*pa != '\0')) {
//		pa++;
//		pb++;
//	}
//	if (*pa > *pb)return 1;
//	else if (*pa < *pb)return -1;
//	else return 0;
//}