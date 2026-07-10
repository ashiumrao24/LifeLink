#ifndef APPLICATION_H
#define APPLICATION_H
#include "donorRepository.h"
#include "requestRepository.h"


class Application
{
public:

    void run();

private:
    DonorRepository donorRepository;
    RequestRepository requestRepository;;

    void showMenu();

    void registerDonor();

    void viewDonors();

    void createBloodRequest();

    void findBestMatches();
};

#endif