#include "src/Controller/ObservableGame_Controller.h"

int main(int argc, char *argv[]) {
    shared_ptr<ObservableGame_Controller> game( new ObservableGame_Controller(argc, argv) );

    return 0;
}
