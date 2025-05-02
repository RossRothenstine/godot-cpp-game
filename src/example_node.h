#pragma once
#ifndef EXAMPLE_NODE_H
#define EXAMPLE_NODE_H

#include <godot_cpp/classes/node.hpp>

namespace gamecode {

using namespace godot;

class ExampleNode : public godot::Node {
  GDCLASS(ExampleNode, Node);

public:
  void example_method();
  int get_example_property() const;
  void set_example_property(int value);

protected:
  static void _bind_methods();

private:
  int _example_property{42};
};

} // namespace gamecode

#endif // EXAMPLE_NODE_H
