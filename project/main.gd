extends Node

@onready var example_node: ExampleNode = $ExampleNode

func _ready() -> void:
	example_node.example_property = 123
	example_node.example_method()
