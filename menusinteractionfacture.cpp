#include "menusinteractionfacture.h"

void MenusInteractionFacture::afficherMenuPrincipal() {
    std::cout << std::endl << "1. Ajouter des Nuitees" << std::endl;
    std::cout << "2. Ajouter des Repas" << std::endl;
    std::cout << "3. Ajouter un acces au Spa" << std::endl;
    std::cout << "4. Ajouter un acces au Gym" << std::endl;
    std::cout << "5. Afficher la facture et quitter" << std::endl;
    std::cout << "Effectuez un choix parmis les options ci-hautes: ";
}

void MenusInteractionFacture::afficherMenuNuitee() {
    std::cout << std::endl << "Combien de nuitees voulez-vous ajouter ? : ";
}

void MenusInteractionFacture::afficherMenuRepas() {
    std::cout << std::endl << "Combien de repas voulez-vous ajouter ? : ";
}

void MenusInteractionFacture::menuNuitees(Facture* facture) {
    int nbNuitees = lireChoix(afficherMenuNuitee);
    FacturableParUnite* nuitee = new FacturableParUnite("Nuitees", 100, nbNuitees);

    try {
        facture->ajouterElementFacturable(nuitee);
    } 
    catch (FacturableInvalidQuantityException& e) {
        std::cout << e.what();
    } 
    catch (FacturableAlreadyAddedException& e) {
        std::cout << e.what();
        facture->forceAjouterElementFacturable(nuitee);
    }
}

void MenusInteractionFacture::menuRepas(Facture* facture) {
    int nbRepas = lireChoix(afficherMenuRepas);
    FacturableParUnite* repas = new FacturableParUnite("Repas", 20, nbRepas);

    try {
        facture->ajouterElementFacturable(repas);
    }
    catch (FacturableInvalidQuantityException& e) {
        std::cout << e.what();
    }
    catch (FacturableAlreadyAddedException& e) {
        std::cout << e.what();
        facture->forceAjouterElementFacturable(repas);
    }
}

void MenusInteractionFacture::menuSpa(Facture* facture) {
    ElementFacturable* element = new FacturableFraisFixe("Spa", 75);

    try {
        facture->ajouterElementFacturable(element);
    }
    catch (FacturableAlreadyAddedException& e) {
        std::cout << e.what();
        facture->forceAjouterElementFacturable(element);
    }
}

void MenusInteractionFacture::menuGym(Facture* facture) {
    ElementFacturable* element = new FacturableFraisFixe("Gym", 50);

    try {
        facture->ajouterElementFacturable(element);
    }
    catch (FacturableAlreadyAddedException& e) {
        std::cout << e.what();
        facture->forceAjouterElementFacturable(element);
    }
}

void MenusInteractionFacture::menuAfficher(Facture* facture) {
    facture->calculerTotal();
    facture->afficherFacture();
}

int MenusInteractionFacture::lireChoix(void(*display)()) {
    int value;
    bool valide = false;

    while (!valide) {
        display();
        std::cin >> value;

        if (!std::cin.fail()) {
            valide = true;
        }
        else {
            std::cout << std::endl << "CE N'EST PAS UN ENTIER VALIDE !!!!" << std::endl;
            std::cin.clear();
            std::cin.ignore(999, '\n');
        }
    }
    return value;
}