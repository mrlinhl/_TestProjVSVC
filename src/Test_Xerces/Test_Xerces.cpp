// ---------------------------------------------------------------------------
//  Simple program which test for XML DOM implementation
//  Version:  Xerces C++ 3.14
// ---------------------------------------------------------------------------

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>

#include <iostream>

using namespace std;
using namespace xercesc;


// ---------------------------------------------------------------------------
//  Recursively Print the Element's TagName and TextContent of the Element
//  which has no child.
// ---------------------------------------------------------------------------
void GetElementData(DOMElement *root) {
  if (root != NULL) {
    DOMElement *child = root->getFirstElementChild();
    char *name = XMLString::transcode(root->getTagName());
    XERCES_STD_QUALIFIER cout << "Encountered Element : " << name << XERCES_STD_QUALIFIER endl;
    XMLString::release(&name);
    if (child == NULL) {
      char* textContent = XMLString::transcode(root->getTextContent());
      XERCES_STD_QUALIFIER cout << "Encountered Text    : " << textContent << XERCES_STD_QUALIFIER endl;
      XMLString::release(&textContent);
    } else {
      XERCES_STD_QUALIFIER cout << "Has child element node ! "  << XERCES_STD_QUALIFIER endl;
      for (; child != 0; child = child->getNextElementSibling())
        GetElementData(child);
    }  
  }
}

int main(int argc, char* args[]) {

  try {
    XMLPlatformUtils::Initialize();
  }
  catch (const XMLException& toCatch) {
    char* message = XMLString::transcode(toCatch.getMessage());
    cout << "Error during initialization! :\n"
      << message << "\n";
    XMLString::release(&message);
    return 1;
  }

  XercesDOMParser* parser = new XercesDOMParser();
  parser->setValidationScheme(XercesDOMParser::Val_Always);
  parser->setDoNamespaces(true);    // optional

  ErrorHandler* errHandler = (ErrorHandler*) new HandlerBase();
  parser->setErrorHandler(errHandler);

  char* xmlFile = "x1.xml";

  try {
    parser->parse(xmlFile);
  }
  catch (const XMLException& toCatch) {
    char* message = XMLString::transcode(toCatch.getMessage());
    cout << "Exception message is: \n"
      << message << "\n";
    XMLString::release(&message);
    return -1;
  }
  catch (const DOMException& toCatch) {
    char* message = XMLString::transcode(toCatch.msg);
    cout << "Exception message is: \n"
      << message << "\n";
    XMLString::release(&message);
    return -1;
  }
  catch (...) {
    cout << "Unexpected Exception \n";
    return -1;
  }

  //Analysis the entire XML document
  DOMDocument *doc = parser->getDocument();
  DOMElement *root = doc->getDocumentElement();

  GetElementData(root);

  delete parser;
  delete errHandler;
  XMLPlatformUtils::Terminate();
  
  return 0;
}
