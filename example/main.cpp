#include <iostream>
#include "YAML-Service/YAML-Service.h"

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "To few arguments!" << std::endl;
        std::cout << "Usage: yaml-service-example <path-to-yaml-file>" << std::endl;
        return 1;
    }

    YamlService yaml_service(argv[1]);

    try {
        std::cout << "int value: " << yaml_service.getInt32Value({"int_value"}) << std::endl;
        std::cout << "float value: " << yaml_service.getFloatValue({"float_value"}) << std::endl;
        std::cout << "double value: " << yaml_service.getDoubleValue({"double_value"}) << std::endl;
        std::cout << "string value: " << yaml_service.getStringValue({"string_value"}) << std::endl;

        std::cout << "int array values: ";
        for (const auto& i : yaml_service.getIntArray({"array_of_ints"})) {
            std::cout << i << " ";
        }
        std::cout << ::std::endl;

        std::cout << "float array values: ";
        for (const auto& f : yaml_service.getFloatArray({"array_of_floats"})) {
            std::cout << f << " ";
        }
        std::cout << ::std::endl;

        std::cout << "nested values:" << std::endl;
        std::cout << "  int value: " << yaml_service.getInt32Value({"nested_values", "nested_int_value"}) << std::endl;
        std::cout << "  float value: " << yaml_service.getFloatValue({"nested_values", "nested_float_value"}) << std::endl;
        std::cout << "  string value: " << yaml_service.getStringValue({"nested_values", "nested_string_value"}) << std::endl;
        std::cout << "  bool value: " << yaml_service.getBoolValue({"nested_values", "nested_bool_value"}) << std::endl;

    } catch (std::exception& e){
        std::cerr << "Exeption, when reading yaml: " << e.what() << std::endl;
    }

    return 0;
}
