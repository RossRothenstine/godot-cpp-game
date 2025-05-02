#include "example_node.h"

namespace gamecode {

void ExampleNode::_bind_methods() {
  ClassDB::bind_method(D_METHOD("example_method"),
                       &ExampleNode::example_method);
  ClassDB::bind_method(D_METHOD("get_example_property"),
                       &ExampleNode::get_example_property);
  ClassDB::bind_method(D_METHOD("set_example_property", "value"),
                       &ExampleNode::set_example_property);
  ADD_PROPERTY(PropertyInfo(Variant::INT, "example_property"),
               "set_example_property", "get_example_property");
}

void ExampleNode::example_method() {
  UtilityFunctions::print("Hello from ExampleNode!! Property: ",
                          _example_property);
}

int ExampleNode::get_example_property() const { return _example_property; }
void ExampleNode::set_example_property(int value) { _example_property = value; }

} // namespace gamecode
