# Umsetzung der 3DVista Virtual Tour für GitHub Pages / LiaScript

## 📁 Projektstruktur
```
├── index.html                # Haupt-HTML-Datei (GitHub Pages optimiert)
├── .nojekyll                 # Deaktiviert Jekyll-Processing für GitHub Pages
├── README.md                 # Diese Dokumentation
├── lib -> data/lib          # Symbolischer Link zu Bibliotheken
├── locale -> data/locale    # Symbolischer Link zu Lokalisierungen
└── data/                    # Hauptdatenverzeichnis
    ├── fonts.css           # Font-Definitionen
    ├── script.js           # Haupt-Konfigurationsskript
    ├── script_general.js   # Desktop-spezifisches Skript
    ├── script_mobile.js    # Mobile-spezifisches Skript
    ├── thumbnail.png       # Vorschaubild
    ├── fonts/              # Schriftarten-Dateien
    ├── lib/                # JavaScript-Bibliotheken
    │   ├── tdvplayer.js   # TDV Player Engine
    │   ├── cursors/       # Cursor-Dateien für Interaktion
    │   └── pdfjs/         # PDF.js für PDF-Anzeige
    ├── locale/             # Sprachdateien
    │   └── de.txt         # Deutsche Lokalisierung
    ├── media/             # Panorama-Bilder und Medien
    ├── skin/              # UI-Grafiken und Icons
    └── files/             # PDF-Dokumente und Downloads
```

## 🔧 Durchgeführte Konfigurationsänderungen

### 1. Pfad-Korrekturen

**Problem:** TourDe360-Export verwendete absolute Pfade (`/lib/`, `/script.js`), die in lokalen Umgebungen nicht funktionieren.

**Lösung:** Alle Pfade zu relativen Pfaden mit `data/`-Prefix geändert:

#### index.html (ursprünglich index.htm)
```html
<!-- Vorher -->
<script type="text/javascript" src="/lib/tdvplayer.js?v=1756890344179"></script>
<script type="text/javascript" src="/script.js?v=1756890344179"></script>

<!-- Nachher -->
<script type="text/javascript" src="data/lib/tdvplayer.js?v=1756890344180"></script>
<script type="text/javascript" src="data/script.js?v=1756890344180"></script>
```

#### data/script.js
```javascript
// Vorher
"devicesUrl": {
    "general": "script_general.js?v=1756890344179",
    "mobile": "script_mobile.js?v=1756890344179"
}

// Nachher  
"devicesUrl": {
    "general": "data/script_general.js?v=1756890344180",
    "mobile": "data/script_mobile.js?v=1756890344180"
}
```

### 2. Symbolische Links

**Problem:** Hardcodierte Pfade in minimierten JavaScript-Dateien (tdvplayer.js) konnten nicht einfach geändert werden.

**Lösung:** Symbolische Links erstellt für Rückwärtskompatibilität:

```bash
# Hauptbibliotheken-Link
ln -s data/lib lib

# Lokalisierungs-Link  
ln -s data/locale locale
```

### 3. PDF.js-Konfiguration

**Problem:** PDF.js suchte nach `.properties`-Dateien, aber nur `.properties.txt`-Dateien waren vorhanden.

**Lösung:** Symbolische Links für PDF.js-Konfigurationsdateien:

```bash
# Haupt-Locale-Datei
cd data/lib/pdfjs/web/locale
ln -sf locale.properties.txt locale.properties

# Englische Lokalisierung
cd en-US/
ln -sf viewer.properties.txt viewer.properties
```

### 4. Locale-Pfad-Korrekturen

**Problem:** Mobile- und Desktop-Skripte verwendeten falschen Locale-Pfad.

**Lösung:** In `script_mobile.js` und `script_general.js`:

```javascript
// Vorher
"locales":{"de":"locale/de.txt"}

// Nachher  
"locales":{"de":"data/locale/de.txt"}
```

### 5. Cache-Busting

**Problem:** Browser-Cache verhinderte das Laden von aktualisierten Dateien.

**Lösung:** Versionsnummer erhöht:
- Von `v=1756890344179` auf `v=1756890344180`

### 6. GitHub Pages Optimierungen

**Problem:** GitHub Pages erwartet spezifische Dateiformate und -strukturen.

**Lösungen implementiert:**
- ✅ `index.htm` → `index.html` umbenannt (GitHub Pages Standard)
- ✅ `.nojekyll`-Datei hinzugefügt (verhindert Jekyll-Processing)
- ✅ Alle relativen Pfade beibehalten (GitHub Pages kompatibel)
- ✅ Repository-Struktur für GitHub Pages optimiert

## ✅ Behobene Probleme

### 404-Fehler behoben:
- ✅ `/lib/tdvplayer.js` → `data/lib/tdvplayer.js`
- ✅ `/script.js` → `data/script.js`  
- ✅ `/script_general.js` → `data/script_general.js`
- ✅ `/script_mobile.js` → `data/script_mobile.js`
- ✅ `/fonts.css` → `data/fonts.css`
- ✅ `/lib/cursors/*.cur` → Symbolischer Link zu `data/lib/cursors/`
- ✅ `/lib/pdfjs/web/locale/locale.properties` → Symbolischer Link
- ✅ `/lib/pdfjs/web/locale/en-US/viewer.properties` → Symbolischer Link
- ✅ `/locale/de.txt` → Symbolischer Link + Skript-Korrektur

### Funktionalität wiederhergestellt:
- ✅ 360°-Panorama-Navigation
- ✅ Hotspot-Interaktion zwischen Szenen
- ✅ PDF-Document-Viewer
- ✅ Cursor-Animationen (grab/grabbing)
- ✅ Responsive Design (Desktop/Mobile)
- ✅ Deutsche Lokalisierung
- ✅ Bildergalerien und Medien-Popups