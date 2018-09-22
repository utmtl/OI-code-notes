/*
 	ԭ����: AC �� 
	�����޸�: memset0 (https://memset0.cn)
	
	�������������������ĳ��ͳ�ƴ���Ļ������޸Ķ�����
	�ѻ��ԭ������Ȩ�� 
	
	��������� AC ������Ļ������޸Ķ�����
	��Ҫ�����ʴɸ��๦�ܣ��Լ�ȷ���ȶ��Եȵȡ�
	�Լ���һЩע�ͣ�������©���� issue ָ����
	ԭ������������ĳЩԭ���޷��ҵ����������Ȩ����ϵ������ / ɾ���� 
	
	TODO:
	1. (DONE) ������ص���Ŀ�޷���ͳ�Ƶ� AC ���е�����
 	2. (DONE) ͳ��ʱչʾ��ǰ��Ŀ�Ѷ� 
 	3. (    ) ͳ��ʱչʾ��ǰ��Ŀ���� 
 	4. ( ING) �������� TXT �ļ���
 	5. (    ) ��������Ϊ����ʱ���������ʶ����ε�����
 	6. (    ) �ʴɶ���û�ͳ�ƺͱȽ� 
 	7. (    ) �ʴɶ��߳� 
 
 */
 #include <bits/stdc++.h>
 #include <windows.h>
 #include <conio.h>
 
 int UserID = 53495; // ���Բ������ 0
 
 #ifdef URLDownloadToFile // ���� URLDownloadToFile �����ظ� 
 #undef URLDownloadToFile
 #endif
 using std::cout;
 using std::endl;
 using std::string;
 
 typedef int (__stdcall *UDF) (LPVOID,LPCSTR,LPCSTR,DWORD,LPVOID);
 
 UDF URLDownloadToFile = (UDF) GetProcAddress(LoadLibrary("urlmon.dll"), "URLDownloadToFileA");
 
 char* strfind(char *text, char *temp) {
     int i = -1, j, l = strlen(temp);
     while (text[++i]) {
         for (j = 0; j < l; j++)
 			if (text[i + j] == 0 || text[i + j] != temp[j])
 				break;
         if (j == l)
 			return text + i + l;
     }
     return 0;
 }
 
 void UTF8ToANSI(char *str) { // ����ȡ���� UTF8 ��ʽ����ҳԴ��ת��Ϊ ANSI ��ʽ 
     int len = MultiByteToWideChar(CP_UTF8, 0, str, -1, 0, 0);
     WCHAR *wsz = new WCHAR[len+1];
     len = MultiByteToWideChar(CP_UTF8, 0,str,-1,wsz,len);
     wsz[len] = 0;
     len = WideCharToMultiByte(CP_ACP, 0, wsz, -1, 0, 0, 0, 0);
     len = WideCharToMultiByte(CP_ACP, 0, wsz, -1, str, len, 0, 0);
     str[len] = 0;
     delete []wsz;
 }
 
 HANDLE hOutput;
 char name[32];
 int count[9], sum;
 
 int GetProblemDifficulty(char *file) { // ��õ�ǰ��Ŀ���Ѷ� 
 	file = strfind(file, "\xE9\x9A\xBE\xE5\xBA\xA6");
 	if (file == NULL) return 8;
 	file = strfind(file, "lg-bg-");
 	if (file[0] == 'r') return 0;
 	if (file[0] == 'o') return 1;
 	if (file[0] == 'y') return 2;
 	if (file[0] == 'g' && file[2] == 'e') return 3;
 	if (file[0] == 'b' && file[4] == 'l') return 4; 
 	if (file[0] == 'p') return 5;
 	if (file[0] == 'b' && file[4] == 'd') return 6;
 	if (file[0] == 'g' && file[2] == 'a') return 7;
 	return 8;
 }
 
 char DiffName[9][32] = {
 	"�����Ѷ�",
 	"�ռ�-",
 	"�ռ�/���-",
 	"�ռ�+/���",
 	"���+/ʡѡ-",
 	"ʡѡ/NOI-",
 	"NOI/NOI+/CTSC",
 	"��������",
 	"δ֪����"
 };
 char DifficultySpace[9][32] = { "     ", "        ", "   ", "   ", "  ", "    ", "", "     ", "     " };
 
 std::map < string, int > ProblemDifficulty;
 std::map < int, std::vector < string > > ProblemCounter;
 
 void Output(char *prob, int diff) { // ��� 
     COORD pos = {0,2};
 	SetConsoleCursorPosition(hOutput, pos); 
     printf("%s ��ͳ��: %s > %s           \n", name, prob, DiffName[diff]);
 	for (int i = 0; i < 9; i++)
 		printf("    %s:%s%6d\n", DiffName[i], DifficultySpace[i], count[i]);
 }
 
 void problem(char *&str) {
     int i = 0,len;
     DWORD unused;
     char prob[32],url[128],*file,*ptr;
     HANDLE hFile;
     
     str = strfind(str, "\">");
     while (*str != '<') prob[i++] = *str++;
 	str = strfind(str, "]\n");
 	
     prob[i] = 0;
     sprintf(url, "https://www.luogu.org/problemnew/show/%s", prob);
     URLDownloadToFile(0, url, "download.tmp", 0, 0);
     hFile = CreateFile("download.tmp", GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
     len = GetFileSize(hFile,0);
     file = ptr = new char[len+3];
     ReadFile(hFile, file, len, &unused,0);
     file[len] = file[len + 1] = 0;
     CloseHandle(hFile);
     
 	int diff = GetProblemDifficulty(file);
 	ProblemDifficulty[prob] = diff;
 	ProblemCounter[diff].push_back(prob);
 	count[diff]++, sum++;
 	Output(prob, diff);
 	
     delete []ptr;
 }
 
 void SaveResult() {
 	std::ofstream fout;
 	char tmp[10000];
 	fout.open("result.txt", std::ios::out);
 	
 	fout << "============================\n"
 			"    �����Ŀ�Ѷ�ͳ�ƽ��    \n"
 			"============================\n\n"
 			"# �û���Ϣ\n\n"
 			"  �û�ID: " << UserID << "\n"
 			"  �û���: " << name << "\n\n"
 			"# ͨ����Ŀ�Ѷȷֲ�\n\n";
 	for (int i = 0; i < 9; i++) {
 		sprintf(tmp, "  %s:%s%6d\n", DiffName[i], DifficultySpace[i], count[i]);
 		fout << tmp;
 	}
 	
 	fout << "\n# ��Ŀ�Ѷ��嵥\n";
 	for (std::map < int, std::vector < string > > ::iterator it = ProblemCounter.begin(); it != ProblemCounter.end(); it++) {
 		sprintf(tmp, "%s", DiffName[it->first]);
 		for (std::vector < string > ::iterator u = it->second.begin(); u != it->second.end(); u++)
 			sprintf(tmp, "%s%c %s", tmp, u == it->second.begin() ? ':' : ',', u->c_str());
 		for (int i = 0; true; i++) {
 			if (!(i % 40) || tmp[i] == '\0') fout << "\n  ";
 			if (tmp[i] == '\0') break;
 			fout << tmp[i];
 		}
 	}
 	fout << "\n  �����������������������Щ���������������������������������\n"
 			"  | ��Ŀ��� |    ��Ŀ���    |\n"
 			"  �����������������������੤��������������������������������\n";
 	for (std::map < string, int > ::iterator it = ProblemDifficulty.begin(); it != ProblemDifficulty.end(); it++) {
 		sprintf(tmp, "  | %8s | %14s |\n", it->first.c_str(), DiffName[it->second]);
 		fout << tmp;
 	}
 	fout << "  �����������������������ة���������������������������������\n";
 	
 	fout.close();
 	system("notepad result.txt");
 }
 
 int main() {
 	
     int len, i = 0;
     DWORD unused;
     char url[128], user[16], *file, *ptr;
     HANDLE hFile;
     hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
     
     if (!UserID) {
 		printf("���������UID: ");
     	scanf("%d", &UserID);
 	} else {
 		printf("���������UID: %d\n", UserID);
 	}
 	
     sprintf(url, "https://www.luogu.org/space/show?uid=%d", UserID);
     URLDownloadToFile(0,url,"download.tmp",0,0);
     hFile = CreateFile("download.tmp",GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
     len = GetFileSize(hFile,0);
     file = new char[len+3];
     ReadFile(hFile,file,len,&unused,0);
     file[len] = file[len+1] = 0;
     CloseHandle(hFile);
     UTF8ToANSI(file);
     
     sprintf(user, "U%d ", UserID);
     ptr = strfind(file, user);
     if (ptr != NULL) {	
         while (ptr[0] != '<' || ptr[1] != '/' || ptr[2] != 'h')
 			name[i++] = *ptr++;
         printf("\n%s ��ͳ��: ", name);
         ptr = strfind(file, "ͨ����Ŀ</h2>\n[<");
         if (ptr) {
             while (*ptr != '<') problem(ptr);
             printf("�ܹ�ͨ������Ŀ��: %d\n", sum);
         } else {
 			printf("δ�ҵ�ͨ������Ŀ\n");
 		}
     } else {
 		printf("�û�������\n");
 	}
 	
     DeleteFile("download.tmp");
     delete []file;
     
 	SaveResult();
 	
     return 0;
 }
