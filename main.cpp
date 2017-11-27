#include <iostream>
#include <string>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost;
using namespace boost::filesystem;

// Path fundamentals
void check_path(const char *p)
{
    path myPath(p);

    if (exists(myPath))
    {
        if (is_regular_file(myPath))
        {
            cout << "path " << myPath.filename().replace_extension() << " is a regular file of size "
                 << file_size(myPath) << endl;
        } else if (is_directory(myPath))
        {
            cout << "path " << myPath.filename() << " is a directory" << endl;
        }
    } else
    {
        cout << "path " << myPath << " does not exists" << endl;
    }
}

// File permissions
void check_file(const path &p)
{
    auto s = status(p);
    auto t = s.type();

    cout << "the type is " << t << endl;

    auto ps = s.permissions();
    if ((ps & owner_write) != owner_write)
    {
        cout << "no permission to write" << endl;
    }
}

// Directory Navigation
void dir_nav(path &dir)
{
    directory_iterator end;
    for (directory_iterator i(dir); i != end; ++i)
    {
        path p = i->path();

        if (is_regular_file(p))
        {
            cout << p.filename() << endl;
        } else if (is_directory(p))
        {
            cout << "directory " << p.filename() << " =================" << endl;
            dir_nav(p);
        }
    }
}

int main(int argc, char *argv[])
{
    // Fundamentals
    cout << "-------- Fundamentals --------" << endl;
    check_path("foo");
    check_path(argv[0]);

    auto dir = path(argv[0]).parent_path();
    check_path(dir.string().c_str());

    for (auto &child : dir)
    {
        cout << child << endl;
    }

    try
    {
        path p("junk");
        cout << file_size(p) << endl;
    }
    catch (const filesystem_error &e)
    {
        cout << e.what() << endl;
    }

    // File status
    cout << endl << "-------- File Status --------" << endl;
    check_file(path(argv[0]));

    // Directory navigation
    cout << endl << "-------- Directory Navigation --------" << endl;
    auto parent = path(argv[0]).parent_path().parent_path();
    dir_nav(parent);

    auto txtFile = path(argv[0]).parent_path() / "text.txt";
    if (is_regular_file(txtFile))
    {
        cout << txtFile << " is a regular file" << endl;
//        remove(txtFile);
    };

    cout << txtFile << endl;

    getchar();
    return 0;
}