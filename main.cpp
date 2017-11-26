#include <iostream>
#include <string>
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    po::options_description desc("Programming options");
    desc.add_options()
            ("help", "print info")
            ("filename", po::value<string>(), "file to process");

    po::variables_map vm;
    auto parsed = po::parse_command_line(argc, argv, desc);
    po::store(parsed, vm);
    po::notify(vm);

    if (vm.count("help"))
    {
        cout << desc << endl;
        getchar();
        return 1;
    }

    string filename = "default.txt";
    if (vm.count("filename")) {
        filename = vm["filename"].as<string>();
    }

    cout << "Processing file " << filename << endl;

    getchar();
    return 0;
}