#include <streamFlow.h>

#include <menu.h>
#include <menu/arduino.h>
#include <menu/arduino/avr.h>
#include <menu/items.h>
#include <menu/IO/rawOut.h>
using namespace AM5;
using namespace AM5::Arduino;
using namespace AM5::Arduino::Avr;

// namespace AM5 {
//   using Root=AM5::RootDef<Framework,Platform>;
// };

// on a C/C++ std machine, but NOT on this .ino file
// #include <menu/std.h>
// using namespace AM5;
// using namespace AM5::Std;

// namespace AM5 {
  using Root=RootDef<Framework,Platform>;
  using Item=Root::Item;
  using Prompt=typename Root::template Prompt<Text<Root>>;
  using Out=AM5::RawOut<
    decltype(Serial),
    Serial,
    Root::Fmt
  >;
// };

Out SerialOut;

inline Out& operator<<(Out& o,Item& i) {
  Serial<<"Out<<Item"<<endl;
  o.out(i);
  return o;
}

Prompt op1("Op 1");

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial<<F("Framework:")<<Framework::Name<<endl;
  Serial<<F("Platform:")<<Platform::Name<<" "<<(sizeof(Platform::Idx)<<3)<<"bits"<<endl;
  Serial<<F("AM5 Tiny def test ---------------")<<endl;
  SerialOut<<op1;
  Serial<<endl;
  Serial<<F("test end ---------------")<<endl;
}

void loop() {}
