#include <gdextension_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "example_node.h"

namespace gamecode {

using namespace godot;

void initialize_gamecode_module(ModuleInitializationLevel p_level) {
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }

  GDREGISTER_CLASS(ExampleNode);
}

void uninitialize_gamecode_module(ModuleInitializationLevel p_level) {
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }
}

} // namespace gamecode

extern "C" {

GDExtensionBool GDE_EXPORT
gamecode_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
                      GDExtensionClassLibraryPtr p_library,
                      GDExtensionInitialization *r_initialization) {
  using namespace godot;
  GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library,
                                          r_initialization);

  init_obj.register_initializer(gamecode::initialize_gamecode_module);
  init_obj.register_terminator(gamecode::uninitialize_gamecode_module);
  init_obj.set_minimum_library_initialization_level(
      MODULE_INITIALIZATION_LEVEL_SCENE);

  return init_obj.init();
}
}
