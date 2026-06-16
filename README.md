# Bracelet d'alerte - Projet IF37

Ce dépôt contient le code final pour le prototype de bracelet de défence autonome développé dans le cadre de l'UE IF37. Le système est conçu pour s'exécuter sur une carte microcontrôleur (XIAO ESP32-S3) et gère des alertes sonores, lumineuses et haptiques.

## Fonctionnalités du Code

Le programme implémente une logique de sécurité basée sur une machine d'états non bloquante :
* **Mode Rassurance / Test (Bouton 1) :** Déclenche une vibration courte du moteur haptique (400 ms) pour confirmer le bon fonctionnement de l'appareil à l'utilisateur, sans activer l'alarme générale.
* **Mode Alerte Générale (Bouton 2) :** Fonctionne comme un commutateur à bascule (*Toggle* On/Off). Une fois activé, il lance un signal de détresse d'urgence.
* **Sirène bifréquence non bloquante :** L'utilisation de la fonction `millis()` (au lieu de `delay()`) permet d'alterner les fréquences du buzzer (3000 Hz et 4200 Hz) et le clignotement de la LED toutes les 100 ms de manière fluide, garantissant que le système reste réactif pour intercepter l'appui de désactivation.

## Brochage (Pinout)

Le câblage des composants sur le PCB est configuré de la manière suivante :

| Composant | Broche (Pin) Arduino | Configuration |
| :--- | :---: | :--- |
| **Bouton de Test** (Bleu) | `1` | Entrée numérique (`INPUT_PULLUP`) |
| **Bouton d'Alerte** (Rouge) | `2` | Entrée numérique (`INPUT_PULLUP`) |
| **Moteur Vibrant** | `4` | Sortie numérique (`OUTPUT`) |
| **LED d'Alerte** | `6` | Sortie numérique (`OUTPUT`) |
| **Buzzer Piézoélectrique** | `43` | Sortie PWM (`OUTPUT` via `tone()`) |

## Installation et Déploiement

1. Installez l'**IDE Arduino**.
2. Configurez le gestionnaire de carte pour prendre en charge votre microcontrôleur (ex: *Seeeduino XIAO ESP32S3*).
3. Copiez le fichier de code dans votre dossier de croquis.
4. Connectez la carte en USB, sélectionnez le bon port COM et téléversez !
