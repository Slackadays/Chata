std::optional<std::vector<std::vector<double>>> readAudioFile(const std::string& filename);
void writeAudioFile(const std::string& filename, const std::vector<std::vector<double>>& data);

std::optional<std::vector<std::vector<double>>> readCSVFile(const std::string& filename);
void writeCSVFile(const std::string& filename, const std::vector<std::vector<double>>& data);