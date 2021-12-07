#include <vector>
#include <yaml-cpp/yaml.h>
#include <fstream>

class YamlService {

public:

    YamlService(std::string yamlPath)
            : yamlPath_(std::move(yamlPath)) {

    };

    uint16_t getUInt16Value(const std::vector<std::string>& keys) { return getNode(keys).as<uint16_t>(); }
    uint32_t getUInt32Value(const std::vector<std::string>& keys) { return getNode(keys).as<uint32_t>(); }
    int32_t getInt32Value(const std::vector<std::string>& keys) { return getNode(keys).as<int32_t>(); }

    float getFloatValue(const std::vector<std::string>& keys) { return getNode(keys).as<float>(); }
    double getDoubleValue(const std::vector<std::string>& keys) { return getNode(keys).as<double>(); }

    std::string getStringValue(const std::vector<std::string>& keys) { return getNode(keys).as<std::string>(); }

    bool getBoolValue(const std::vector<std::string>& keys) { return getNode(keys).as<bool>(); }
    std::vector<float> getFloatArray(const std::vector<std::string>& keys) { return getNode(keys).as<std::vector<float>>(); }

    std::vector<int> getIntArray(const std::vector<std::string>& keys) { return getNode(keys).as<std::vector<int>>(); }
    std::vector<YAML::Node> getNodeArray(const std::vector<std::string>& keys) { return getNode(keys).as<std::vector<YAML::Node>>(); }

    YAML::Node getRawYaml() {return YAML::LoadFile(yamlPath_);};

protected:

    const std::string yamlPath_;

    YAML::Node getNode(const std::vector<std::string>& keys) {
        YAML::Node yaml = YAML::LoadFile(yamlPath_);
        for (const auto& key : keys) {
            if (yaml[key]) {
                yaml = yaml[key];
            } else {
                throw std::runtime_error("Unable to read \"" + key + "\" from config file!");
            }
        }
        return yaml;
    }
};
