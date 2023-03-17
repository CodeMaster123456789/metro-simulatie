#include "../lib/DesignByContract.h"
#include "MetroImporter.h"
#include "../lib/tinyxml.h"

using namespace std;


//Auxiliary function for internal use only

const std::string fetch_text(TiXmlNode *pElement, std::ostream& errStream) {
	if (pElement == NULL) return "";
	
	TiXmlNode *elemNode = pElement->FirstChild();
	if (elemNode == NULL) return "";
	TiXmlText* text = elemNode->ToText();
	if(text == NULL) return "";  
	return text->Value();
}

//Below is a static member function but one cannot repeat the static keyword in the implementation

SuccessEnum MetroImporter::importMetro(
        const char * inputfilename, std::ostream& errStream, Metro& simulatie) {
	
	TiXmlDocument doc;
	SuccessEnum endResult = Success;

	REQUIRE(simulatie.properlyInitialized(), "Metro simulatie wasn't initialized");
	
	if(!doc.LoadFile(inputfilename)) {
		errStream << "XML IMPORT ABORTED: " << doc.ErrorDesc() << endl;
		return ImportAborted;
	};
    
    doc.Clear();

	return endResult;
}