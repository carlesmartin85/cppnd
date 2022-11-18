export module mainmodule:partition;

import <cstring>;

export namespace ptt{

	char* copyString(const char *str){
		char *result{new char[strlen(str)+1]};
		strcpy(result, str);
		return result;
	}

	char* appendStrings(const char *str1, const char *str2, const char *str3){
		char *result{new char[strlen(str1) + strlen(str2) + strlen(str3) + 1]};
		strcpy(result, str1);
		strcat(result, str2);
		strcat(result, str3);
		return result;
	}

}