# 360°-Virtual Tour - TourDe360

Eine interaktive 360°-Virtual Tour erstellt mit TourDe360/TDV Player. Diese Tour bietet immersive Panorama-Navigation mit Hotspots, integrierten PDF-Viewern und responsivem Design.

## 🚀 Schnellstart

```bash
# In das Projektverzeichnis wechseln
cd /path/to/project

# HTTP-Server starten
python3 -m http.server 8000

# Tour im Browser öffnen
# http://localhost:8000
```

## 📁 Projektstruktur

```
├── index.htm                 # Haupt-HTML-Datei
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

#### index.htm
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

## 🌐 Features der Virtual Tour

### Navigation
- **360°-Panorama-Ansicht** mit Maus/Touch-Steuerung
- **Hotspot-Navigation** zwischen verschiedenen Räumen/Szenen
- **Zoom-Funktionalität** für detaillierte Betrachtung
- **Vollbild-Modus** verfügbar

### Medien-Integration
- **PDF-Viewer** für Dokumente direkt im Browser
- **Bildergalerien** mit Thumbnail-Navigation
- **Responsive Design** für Desktop und Mobile

### Interaktive Elemente
- **Hotspots** mit Hover-Effekten
- **Informations-Popups** für Details
- **Download-Links** für PDF-Dateien
- **Mehrsprachige Unterstützung** (Deutsch)

## 🛠️ Technische Details

### Verwendete Technologien
- **TDV Player** - 360°-Panorama-Engine
- **PDF.js** - PDF-Anzeige im Browser  
- **WebGL** - Hardware-beschleunigte Grafik
- **Responsive CSS** - Mobile Optimierung

### Browser-Kompatibilität
- Chrome/Chromium (empfohlen)
- Firefox
- Safari
- Edge

### Performance-Optimierungen
- **Cubic Map Tiles** - Effiziente Panorama-Aufteilung
- **Progressive Loading** - Bilder laden bei Bedarf
- **Cache-Headers** - Optimierte Browser-Caches

## 📋 Deployment

### Lokale Entwicklung
```bash
python3 -m http.server 8000
# oder
npx http-server -p 8000
# oder  
php -S localhost:8000
```

### Produktions-Deployment
1. Gesamten Projektordner auf Webserver hochladen
2. Symbolische Links müssen unterstützt werden (Linux/Unix-Server)
3. Alternativ: Symbolische Links durch echte Kopien ersetzen:

```bash
# Symbolische Links durch Kopien ersetzen
rm lib locale
cp -r data/lib ./lib
cp -r data/locale ./locale
```

## 🐛 Troubleshooting

### Häufige Probleme

**Problem:** 404-Fehler für Ressourcen
**Lösung:** HTTP-Server verwenden, nicht direkt file:// öffnen

**Problem:** Panoramas laden nicht
**Lösung:** Browser-Cache leeren, CORS-Einstellungen prüfen

**Problem:** PDF-Viewer zeigt Fehler
**Lösung:** Sicherstellen, dass PDF.js-Locale-Links existieren

**Problem:** Mobile Navigation funktioniert nicht
**Lösung:** Touch-Events im Browser aktivieren

## 📝 Changelog

### Version 1.1 (2025-09-28)
- ✅ Alle Pfad-Probleme behoben
- ✅ PDF.js vollständig konfiguriert  
- ✅ Symbolische Links für Kompatibilität
- ✅ Cache-Busting implementiert
- ✅ Deutsche Lokalisierung korrigiert
- ✅ Mobile/Desktop-Skripte repariert

### Version 1.0 (Original Export)
- 🔴 Absolute Pfade (nicht funktionsfähig)
- 🔴 Fehlende PDF.js-Konfiguration
- 🔴 Gebrochene Locale-Pfade

## 🤝 Support

Bei Problemen oder Fragen:
1. Browser-Konsole auf Fehler prüfen (F12)
2. Netzwerk-Tab auf 404-Fehler überprüfen
3. HTTP-Server statt file:// verwenden
4. Cache leeren und neu laden

## 📄 Lizenz

Projekt basiert auf TourDe360/TDV Player. Siehe entsprechende Lizenzbestimmungen in den lib-Ordnern.