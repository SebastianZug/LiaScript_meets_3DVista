# 🔧 Technische Änderungen - 3DVista Tour für GitHub Pages

Dieses Dokument beschreibt alle notwendigen Modifikationen, die am ursprünglichen TourDe360-Export vorgenommen wurden, um die Virtual Tour auf GitHub Pages lauffähig zu machen.

## 🏗️ Hauptprobleme des Original-Exports

Der ursprüngliche TourDe360-Export war **nicht lauffähig** aufgrund mehrerer struktureller Probleme:

1. **❌ Absolute Pfade:** `/lib/tdvplayer.js`, `/script.js` → 404-Fehler
2. **❌ Fehlende PDF.js-Konfiguration:** `.properties`-Dateien fehlten
3. **❌ Gebrochene Lokalisierung:** Falsche Locale-Pfade in JavaScript
4. **❌ GitHub Pages inkompatibel:** `index.htm` statt `index.html`
5. **❌ Cache-Probleme:** Alte Versionsnummern
6. **❌ PDF-Downloads defekt:** JavaScript-Pfadmanipulation

## ⚡ Kritische Korrekturen (notwendig für Funktionsfähigkeit)

### 1. **Pfad-System komplett überarbeitet**
```bash
# Alle absoluten Pfade korrigiert:
/lib/tdvplayer.js        → data/lib/tdvplayer.js
/script.js               → data/script.js  
/script_general.js       → data/script_general.js
/script_mobile.js        → data/script_mobile.js
/fonts.css               → data/fonts.css
```

### 2. **Symbolische Links für Kompatibilität**
```bash
ln -s data/lib lib                # Haupt-Bibliotheken
ln -s data/locale locale          # Lokalisierungen
ln -s locale.properties.txt locale.properties    # PDF.js
ln -s viewer.properties.txt viewer.properties    # PDF.js EN
```

### 3. **JavaScript-Konfiguration repariert**
- **script.js:** Device-URLs von `/` zu `data/` korrigiert
- **script_mobile.js + script_general.js:** Locale-Pfade repariert
- **Alle Skripte:** Cache-Busting Version aktualisiert

### 4. **PDF-System komplett repariert (Version 1.5)**
- **openLink-Funktion:** Problematische Pfadmanipulation entfernt
- **Lokalisierungsdateien:** Alle PopupPDFBehaviour-URLs korrigiert
- **6 PDF-Downloads:** Von defekt zu vollständig funktionsfähig

## ✅ Endresultat - Vollständig funktionsfähige Tour

**Alle ursprünglichen Funktionen wiederhergestellt:**
- ✅ 360°-Panorama-Navigation zwischen 23 Szenen
- ✅ Interaktive Hotspots und Navigationspunkte  
- ✅ PDF-Document-Viewer mit 6 funktionsfähigen Downloads
- ✅ Responsive Design (Desktop + Mobile optimiert)
- ✅ Deutsche Lokalisierung komplett
- ✅ Bildergalerien und Video-Popups
- ✅ Cursor-Animationen und UI-Feedback

**GitHub Pages & LiaScript Integration:**
- ✅ Live verfügbar: https://sebastianzug.github.io/LiaScript_meets_3DVista/
- ✅ LiaScript-Integration für Bildungskontext
- ✅ Keine Jekyll-Konflikte durch `.nojekyll`
- ✅ Optimierte Performance durch Video-Komprimierung

## � Detaillierte Korrekturen (für Entwickler)

<details>
<summary><strong>🔧 Pfad-Korrekturen im Detail</strong></summary>

### index.html (ursprünglich index.htm)
```html
<!-- Absolute Pfade (Original) -->
<script src="/lib/tdvplayer.js?v=1756890344179"></script>
<script src="/script.js?v=1756890344179"></script>

<!-- Relative Pfade (Korrigiert) -->  
<script src="data/lib/tdvplayer.js?v=1756890344180"></script>
<script src="data/script.js?v=1756890344180"></script>
```

### data/script.js
```javascript
// Gebrochene Device-URLs (Original)
"devicesUrl": {
    "general": "script_general.js?v=1756890344179",
    "mobile": "script_mobile.js?v=1756890344179"
}

// Funktionsfähige Pfade (Korrigiert)
"devicesUrl": {
    "general": "data/script_general.js?v=1756890344180", 
    "mobile": "data/script_mobile.js?v=1756890344180"
}
```

</details>

<details>
<summary><strong>🔗 Symbolische Links</strong></summary>

```bash
# Rückwärtskompatibilität für hardcodierte Pfade
ln -s data/lib lib
ln -s data/locale locale

# PDF.js-Konfiguration
cd data/lib/pdfjs/web/locale/
ln -sf locale.properties.txt locale.properties
cd en-US/
ln -sf viewer.properties.txt viewer.properties
```

</details>

<details>
<summary><strong>📄 PDF-System Reparatur (v1.5)</strong></summary>

### JavaScript openLink-Funktion korrigiert:
```javascript
// DEFEKT: Machte relative zu absoluten Pfaden
if(c&&b=='_blank'){a['startsWith']('data/files/')&&(a='/'+a);

// REPARIERT: Pfade unverändert lassen  
if(c&&b=='_blank'){if(a['startsWith']('//'))a='https:'+a;
```

### Lokalisierungsdateien repariert:
```txt
# 6 PopupPDFBehaviour-URLs korrigiert:
files/Anleitung_Arduino_de.pdf → data/files/Anleitung_Arduino_de.pdf
files/Praktikumsanleitung_Teil1_Einführung&Grundlagen_de.pdf → data/files/Praktikumsanleitung_Teil1_Einführung&Grundlagen_de.pdf
[...weitere 4 PDFs...]
```

</details>

---

## 🚀 Für neue Installationen

**Um eine neue 3DVista-Tour GitHub Pages-kompatibel zu machen:**

1. **Pfade korrigieren:** Alle `/lib/`, `/script.js` etc. zu `data/` 
2. **Symbolische Links erstellen:** Für Rückwärtskompatibilität
3. **PDF.js konfigurieren:** `.properties`-Links erstellen
4. **GitHub Pages Setup:** `index.html`, `.nojekyll`
5. **Cache-Busting:** Versionsnummern aktualisieren
6. **PDF-Downloads testen:** openLink-Funktion überprüfen

💡 **Tipp:** Diese Korrekturen sind bei jedem TourDe360-Export notwendig, da der Export immer absolute Pfade verwendet.