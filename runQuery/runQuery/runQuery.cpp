//FIRST CODE
#include "header.h"


using namespace std;
int ITK_user_main(int argc, char* argv[]){
	printf("Utility started execution...\n");
	int iFail = ITK_ok;
	iFail = ITK_auto_login();
	//iFail = ITK_init_module("infodba","infodba","dba");
	if(iFail!=ITK_ok)
	{
		printf("Auto login unsuccessful\n");
		return iFail;
	}
	printf("Auto login successful\n");
	//FIND QUERY
	tag_t tQryTag = NULLTAG;
	utils::report_error(QRY_find("General...",&tQryTag));
	if(tQryTag!=NULLTAG){
		printf("Query found\n");
		//CREATE QRY INPUTS
		int tEntryCnt = 1;
		char* cValue1 = "Item";
		char* cEntries[] = {"Type"};
		char** cValues = (char**)calloc(tEntryCnt,sizeof(char*));
		if(!cValues){
			printf("Memory allocation failed for cValues\n");
			utils::report_error(1);
			return 1;
		}
		cValues[0]=(char*)calloc(strlen(cValue1)+1,sizeof(char));
		if(!cValues[0]){
			printf("Memory allocation failed for cValues[0]\n");
			MEM_free(cValues);
			cValues=NULL;
			utils::report_error(1);
			return 1;
		}
		strcpy_s(cValues[0],strlen(cValue1) + 1,cValue1);
		//RUN QUERY
		int iCnt;
		tag_t* tQryTags = NULL;
		utils::report_error(QRY_execute(tQryTag,tEntryCnt,cEntries,cValues,&iCnt,&tQryTags));
		printf("Query count 1= %d\n",iCnt);
		for(int i=0;i<tEntryCnt;i++){
			MEM_free(cValues[i]);
		}
		printf("Query count 2= %d\n",iCnt);
		/*if( iCnt > 0 ){
			printf("Query count 3= %d\n",iCnt);
		}*/
		if (tQryTags) {
			MEM_free(tQryTags);
		}
		MEM_free(cValues);
		
	}else{
		printf("Query not found\n");
	}
	ITK_exit_module(true);
	return iFail;
}


//SECOND CODE	
//#include "header.h"
//#include <memory>
//#include <cstring>
//
//struct MemDeleter {
//	void operator()(tag_t* ptr) const {
//		if (ptr) MEM_free(ptr);
//	}
//};
//
//using namespace std;
//
//int ITK_user_main(int argc, char* argv[]) {
//	printf("Utility started execution...\n");
//	std::unique_ptr<tag_t, MemDeleter> tRawTags;
//	int iFail = ITK_ok;
//	iFail = ITK_auto_login();
//
//	if (iFail != ITK_ok) {
//		printf("Auto login unsuccessful\n");
//		return iFail;
//	}
//	printf("Auto login successful\n");
//	tag_t tQryTag = NULLTAG;
//	utils::report_error(QRY_find("General...", &tQryTag));
//	if (tQryTag != NULLTAG) {
//		printf("Query found\n");
//		int tEntryCnt = 1;
//		const char* cValue1 = "Item";
//		 char* cEntries[] = {"Type"};
//
//		// Use smart pointer for dynamic array allocation
//		unique_ptr<char*[]> cValues(new char*[tEntryCnt]);
//		if (!cValues) {
//			printf("Memory allocation failed for cValues\n");
//			return 1;
//		}
//
//		// Allocate memory for the first entry
//		cValues[0] = new char[strlen(cValue1) + 1];
//		if (!cValues[0]) {
//			printf("Memory allocation failed for cValues[0]\n");
//			return 1;
//		}
//
//		// Copy string safely
//		strcpy_s(cValues[0], strlen(cValue1) + 1, cValue1);
//		int iCnt = 0;
//		tag_t* tQryTags = nullptr;
//
//		// Smart pointer with custom deleter for query execution
//		utils::report_error(QRY_execute(tQryTag, tEntryCnt, cEntries, cValues.get(), &iCnt, &tQryTags));
//		tRawTags.reset(tQryTags);
//		if (iCnt > 0) {
//			printf("Query count = %d\n", iCnt);
//		}
//
//		// Clean up dynamically allocated strings
//		utils::cleanUpStrings(cValues.get(),tEntryCnt);
//
//	} else {
//		printf("Query not found\n");
//	}
//	ITK_exit_module(true);
//	return iFail;
//}


