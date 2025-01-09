#!/bin/bash

# clean_philo.sh
# Script pour nettoyer la sortie du programme philosophers et limiter le nombre de lignes

# Fonction d'aide
show_usage() {
    echo "Usage: $0 [-n nb_lines] nb_philo time_to_die time_to_eat time_to_sleep [nb_times_to_eat]"
    echo "Options:"
    echo "  -n nb_lines : Nombre de lignes à capturer (optionnel)"
    exit 1
}

# Initialisation des variables
nb_lines=""
output_file="philo.out"

# Traitement des options
while getopts "n:h" opt; do
    case $opt in
        n) nb_lines=$OPTARG ;;
        h) show_usage ;;
        ?) show_usage ;;
    esac
done

# Décale les paramètres pour ignorer les options
shift $((OPTIND-1))

# Vérifie si assez d'arguments ont été fournis
if [ $# -lt 4 ]; then
    show_usage
fi

# Exécute le programme avec ou sans limitation de lignes
if [ -n "$nb_lines" ]; then
    # Avec limitation de lignes
    ./philo "$@" | sed 's/\x1b\[[0-9;]*m//g' | head -n "$nb_lines" > "$output_file"
    echo "Les $nb_lines premières lignes ont été sauvegardées dans $output_file"
else
    # Sans limitation de lignes
    ./philo "$@" | sed 's/\x1b\[[0-9;]*m//g' > "$output_file"
    echo "La sortie complète a été sauvegardée dans $output_file"
fi