// Richard Son

#include <iostream> 
#include <stdlib.h> // getenv call
#include <sys/sysinfo.h> // system uptime call
#include <cgicc/Cgicc.h> // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include <string>
#include "GPIO.h"

#define LED_GPIO "/sys/class/gpio/gpio60/"
#define BUTTON_GPIO "/sys/class/gpio/gpio46/"

using namespace std;
using namespace cgicc;
using namespace exploringBB;

void writeGPIO(string filename, string value){
    fstream fs;
    string path(LED_GPIO);
    fs.open((path + filename).c_str(), fstream::out);
    fs << value;
    fs.close();
}

void readGPIO(string filename){
    fstream fs;
    string line;
    string path(BUTTON_GPIO);
    fs.open((path+filename).c_str(), fstream::in);
    fs >> line;
    fs.close();
}

int main(){
    Cgicc form;

    GPIO button(46);
/*    
// get the state of the form that was submitted
    bool isStatus = form.queryCheckbox("status");
    form_iterator it = form.getElement("cmd"); // radio command
    if (it == form.getElements().end() || it->getValue() == "")
        cmd = "off";    // if it is invalid use "off"
    else
        cmd = it->getValue();   // otherwise use submitted value
    char *value = getenv("REMOTE_ADDR");        // the remote IP address
*/
// generate the form but use states that are set in the submitted form

    cout << HTTPHTMLHeader() << endl;   // Generate the HTML form
    cout << html() << head() << title("Homework 10 problem 2") << head() << endl;
    cout << body() << h1("CPE 422 Reading a Pushbutton as digital input") << endl;
    cout << body() << h1("Reading a Pushbutton on gpio46 via a Web Browser") << endl;
    
    cout << "<form action =\"/cgi-bin/read_button.cgi\" method =\"POST\">\n";
    cout << "<div> <input type = \"Submit\" value =\"Read Button\" />";
    cout << "</div></form>";

// Push button state
    cout << body() << h1("Pushbutton State") << endl;
   // if (button.read(BUTTON_GPIO,"value") == "1")
    if (button.getValue()){
        cout << h1("Button Not Pressed");
        cout << button.getValue();
}
    else{
        cout << h1("Button Pressed");
        cout << button.getValue();
}
    cout << body() << html();

}
