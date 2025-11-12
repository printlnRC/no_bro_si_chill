from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.common.exceptions import WebDriverException, TimeoutException
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

# --- 1. Initialisation SÛRE du Driver ---
driver = None  
wait = None
URL = "http://82.66.246.174:26/view/viewer_index.shtml?id=770"
SETUP_BUTTON_ID = "view_SetTxt1" # L'ID confirmé !

try:
    print("Tentative d'initialisation du WebDriver (Firefox)...")
    
    # Isoler l'initialisation pour capturer l'erreur GeckoDriver
    try:
        driver = webdriver.Firefox()
        # Attente maximale de 15 secondes pour les éléments
        wait = WebDriverWait(driver, 15) 
        print("WebDriver initialisé avec succès.")
    except WebDriverException as e:
        print("\n--- ÉCHEC DE L'INITIALISATION DU WEBDRIVER ---")
        print("ACTION REQUISE : Vérifiez que 'geckodriver' est installé et dans votre PATH.")
        print(f"MESSAGE D'ERREUR : {e.msg.splitlines()[0]}")
        raise 

    # --- 2. Ouvrir le site web ---
    print(f"Ouverture de la page : {URL}")
    driver.get(URL)
    
    # --- 3. Attendre et Cliquer sur le bouton "Setup" ---
    
    print(f"Recherche et attente du bouton 'Setup' (ID: {SETUP_BUTTON_ID})...")
    
    try:
        # Cette ligne est la clé : elle attend que l'élément soit présent et cliquable
        setup_button = wait.until(
            EC.element_to_be_clickable((By.ID, SETUP_BUTTON_ID))
        )
        
        # 4. Exécution du clic
        print("**CLIC RÉUSSI** : Bouton 'Setup' trouvé et cliqué.")
        setup_button.click()
        
    except TimeoutException:
        print(f"ÉCHEC : Le bouton avec l'ID '{SETUP_BUTTON_ID}' n'est pas apparu ou n'est pas cliquable après 15 secondes.")
        
    time.sleep(5) # Pause pour voir la page de configuration

except Exception as e:
    # Capture d'erreurs générales après l'initialisation
    print(f"\nUne erreur inattendue s'est produite durant l'exécution du script : {e}")

finally:
    # --- 5. Fermer le navigateur ---
    if driver is not None:
        print("Fermeture du navigateur.")
        driver.quit()
    else:
        print("Le navigateur n'a jamais été ouvert.")