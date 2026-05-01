# Commande-de-moteurs-d-un-robot-mobile-2022
Étude et réalisation du pilotage des moteurs d'un robot mobile autonome à base de microcontrôleur PIC18F4580. Le robot dispose de deux roues de traction motorisées, de codeurs pour l'odométrie, d'un capteur ultrason HC-SR04 et d'un servomoteur FS90 pour la détection d'obstacles. Projet n°2 – Groupe 3, UV EN41.
# Projet EN41 – Commande de moteurs d'un robot mobile
### Groupe 3 – Projet n°2 | UV EN41 – Techniques et outils de conception en électronique

---

## Description

Ce projet a pour objectif l'étude et la réalisation du **pilotage des moteurs** d'un robot mobile autonome (« robot mobile 1 »).  
Le robot est une plateforme à 2 roues de traction motorisées et 1 roue libre, contrôlée par un microcontrôleur **PIC18F4580**.

---

## Architecture matérielle

| Composant | Rôle |
|---|---|
| **PIC18F4580** | Gestion globale du robot (unité centrale) |
| **Moteur M1 / M2** | Traction des roues gauche et droite |
| **Codeurs (x2)** | Mesure de la vitesse et du déplacement angulaire de chaque roue |
| **Capteur HC-SR04** | Détection d'obstacles à ultrasons (projet n°1) |
| **Servomoteur FS90** | Orientation du capteur ultrason |
| **Étage puissance** | Amplification des signaux de commande vers les moteurs |
| **Écran LCD** | Affichage de la vitesse, direction et informations du robot |

---

## Fonctionnement

- En mode normal, le robot **avance en ligne droite** à vitesse lente et constante.
- Les **codeurs** fournissent en retour la vitesse et le déplacement angulaire de chaque roue.
- Les **signaux de commande** issus du PIC transitent par un étage puissance avant d'alimenter les moteurs.
- Le capteur HC-SR04 (monté sur le servomoteur FS90) permet au robot de fonctionner en **mode autonome**.
- Un écran **LCD** permet d'afficher la vitesse, la direction et d'autres informations relatives au robot.

---

## Répartition des projets

| Projet | Groupe | Sujet |
|---|---|---|
| Projet n°1 | Groupe dédié | Détection d'obstacles (capteur HC-SR04) |
| **Projet n°2** | **Groupe 3** | **Commande des moteurs (PIC18F4580)** |

---

## Structure du projet
