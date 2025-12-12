#include <cstddef>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

static std::string replace_str(std::string text, std::string s1, std::string s2)
{
	if (s1.empty())
		return text;
	std::string result;
	size_t		pos = 0;

	while (true)
	{
		size_t found = text.find(s1, pos);
		if (found == std::string::npos)
		{
			result += text.substr(pos);
			break;
		}
		result += text.substr(pos, found - pos);
		result += s2;
		pos = found + s1.size();
	}
	return result;
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	const std::string filename = argv[1];
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];
	if (s1.empty()) {
		std::cerr << "Error: s1 must not be empty." << std::endl;
		return 1;
	}
	std::fstream in(filename.c_str());
	if (!in) {
		std::cerr << "Error: cannot open input file." << filename << std::endl;
		return 1;
	}
	std::ostringstream buffer;
	buffer << in.rdbuf();
	std::string content = buffer.str();
	in.close();

	std::string replaced = replace_str(content, s1, s2);
	std::ofstream out((filename + ".replace").c_str());
	if (!out) {
		std::cerr << "Error: cannot create output file: " << filename << ".replace" << std::endl;
		return 1;
	}
	out << replaced;
	out.close();
}
