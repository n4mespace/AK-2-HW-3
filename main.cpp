#include <stdio.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char **argv)
{
    const char *help_msg =
        "\n\tThis tool has basic CRUD capabilities:\n\
        -h, --help                                       : Display this message\n\
        -v, --version                                    : Display version info\n\
        -r [<filename>, ...], --read=[<filename>, ...]   : Read specified files\n\
        -c [<filename>, ...], --create=[<filename>, ...] : Create specified files\n\
        -u [<filename>, ...], --update=[<filename>, ...] : Update specified files\n\
        -d [<filename>, ...], --delete=[<filename>, ...] : Delete specified files\n";

    static struct option longOpts[] = {
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {"create", required_argument, 0, 'c'},
        {"read", required_argument, 0, 'r'},
        {"update", required_argument, 0, 'u'},
        {"delete", required_argument, 0, 'd'},
        {0, 0, 0, 0},
    };
    static const char *optString = "c:r:u:d:hv";

    int c = getopt_long(argc, argv, optString, longOpts, 0);

    struct globalArgs_t
    {
        bool c_filename;
        bool r_filename;
        bool u_filename;
        bool d_filename;
        bool show_help;
        bool show_version;
    } globalArgs;

    globalArgs.c_filename = false;
    globalArgs.r_filename = false;
    globalArgs.u_filename = false;
    globalArgs.d_filename = false;
    globalArgs.show_help = false;
    globalArgs.show_version = false;

    while (c != -1)
    {
        switch (c)
        {
        case 'h':
            if (!globalArgs.show_help)
            {
                globalArgs.show_help = true;
                printf("%s\n", help_msg);
            }
            break;

        case 'v':
            if (!globalArgs.show_version)
            {
                globalArgs.show_version = true;
                printf("Version 0.1.0\n");
            }
            break;

        case 'c':
            if (!globalArgs.c_filename)
            {
                char *args;
                args = strtok(optarg, ",");
                while (args != NULL)
                {
                    printf("Creating a file: %s\n", args);
                    args = strtok(NULL, ",");
                }
                globalArgs.c_filename = true;
            }
            else
            {
                printf("To create more than 1 file use list of filenames\n");
            }
            break;

        case 'r':
            if (!globalArgs.r_filename)
            {
                char *args;
                args = strtok(optarg, ",");
                while (args != NULL)
                {
                    printf("Reading a file: %s\n", args);
                    args = strtok(NULL, ",");
                }
                globalArgs.r_filename = true;
            }
            else
            {
                printf("To read more than 1 file use list of filenames\n");
            }
            break;

        case 'u':
            if (!globalArgs.u_filename)
            {
                char *args;
                args = strtok(optarg, ",");
                while (args != NULL)
                {
                    printf("Updating a file: %s\n", args);
                    args = strtok(NULL, ",");
                }
                globalArgs.u_filename = true;
            }
            else
            {
                printf("To update more than 1 file use list of filenames\n");
            }
            break;

        case 'd':
            if (!globalArgs.d_filename)
            {
                char *args;
                args = strtok(optarg, ",");
                while (args != NULL)
                {
                    printf("Deleting a file: %s\n", args);
                    args = strtok(NULL, ",");
                }
                globalArgs.d_filename = true;
            }
            else
            {
                printf("To delete more than 1 file use list of filenames\n");
            }
            break;

        default:
            break;
        }

        c = getopt_long(argc, argv, optString, longOpts, 0);
    }

    if (argc < 2)
    {
        printf("%s\n", help_msg);
    }

    return 0;
}