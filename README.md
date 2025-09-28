# 360°-Virtual Tour - TourDe360

Eine interaktive 360°-Virtual Tour erstellt mit TourDe360/TDV Player. Diese Tour bietet immersive Panorama-Navigation mit Hotspots, integrierten PDF-Viewern und responsivem Design.

## 🚀 Schnellstart

### Live-Demo (GitHub Pages)
**🌐 https://sebastianzug.github.io/LiaScript_meets_3DVista/**

### Lokale Entwicklung
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

### GitHub Pages (Empfohlen) 🌐
**Live-URL:** https://sebastianzug.github.io/LiaScript_meets_3DVista/

#### Setup-Schritte:
1. **Repository zu GitHub pushen:**
   ```bash
   git remote add origin https://github.com/SebastianZug/LiaScript_meets_3DVista.git
   git push -u origin main
   ```

2. **GitHub Pages aktivieren:**
   - Gehe zu Repository-Settings
   - Navigiere zu "Pages"
   - Wähle Source: "Deploy from a branch"
   - Branch: `main`, Folder: `/ (root)`
   - Klicke "Save"

3. **Warten:** 5-10 Minuten bis Deployment abgeschlossen

#### GitHub Pages Vorteile:
- ✅ **Kostenlos** und automatisch aktualisiert
- ✅ **HTTPS** standardmäßig aktiviert
- ✅ **CDN-Cache** für weltweite Performance
- ✅ **Automatische Builds** bei Git-Push
- ✅ **Custom Domain** optional möglich

### Lokale Entwicklung
```bash
python3 -m http.server 8000
# oder
npx http-server -p 8000
# oder  
php -S localhost:8000
```

### Alternative Produktions-Deployments
1. **Traditioneller Webserver:**
   - Gesamten Projektordner auf Webserver hochladen
   - Symbolische Links müssen unterstützt werden (Linux/Unix-Server)
   - Alternativ: Symbolische Links durch echte Kopien ersetzen:

```bash
# Symbolische Links durch Kopien ersetzen
rm lib locale
cp -r data/lib ./lib
cp -r data/locale ./locale
```

2. **Netlify/Vercel Alternative:**
   - Drag & Drop Deployment möglich
   - Automatische HTTPS und CDN
   - Git-Integration verfügbar

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

**Problem:** GitHub Pages zeigt 404-Fehler
**Lösung:** 
- Sicherstellen, dass `index.html` (nicht .htm) verwendet wird
- `.nojekyll`-Datei muss vorhanden sein
- Deployment-Status in GitHub Actions überprüfen

**Problem:** GitHub Pages Build-Fehler
**Lösung:**
- Repository-Settings → Pages überprüfen
- Branch und Folder korrekt eingestellt (main, / root)
- Commit und Push durchführen, dann 5-10 Minuten warten

## 📝 Changelog

### Version 1.2 (2025-09-28) - GitHub Pages Ready 🌐
- ✅ **GitHub Pages Deployment** konfiguriert und live
- ✅ `index.htm` → `index.html` umbenannt
- ✅ `.nojekyll`-Datei hinzugefügt
- ✅ **Live-URL verfügbar:** https://sebastianzug.github.io/LiaScript_meets_3DVista/
- ✅ Repository vollständig dokumentiert
- ✅ Deployment-Anweisungen hinzugefügt

### Version 1.1 (2025-09-28) - Lokale Fixes
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

### Lokale Entwicklung:
1. Browser-Konsole auf Fehler prüfen (F12)
2. Netzwerk-Tab auf 404-Fehler überprüfen
3. HTTP-Server statt file:// verwenden
4. Cache leeren und neu laden

### GitHub Pages Probleme:
1. **URL prüfen:** https://sebastianzug.github.io/LiaScript_meets_3DVista/
2. **Deployment-Status:** Repository → Actions oder Environments
3. **Warte-Zeit:** 5-10 Minuten nach Git-Push
4. **Settings prüfen:** Repository → Settings → Pages
5. **Browser-Cache leeren** bei Aktualisierungen

### Deployment-Status prüfen:
- ✅ **Aktiv:** Grüner Punkt bei Environments
- 🟡 **Building:** Gelber Punkt, warten...
- 🔴 **Fehler:** Rote Markierung, Logs prüfen

## 📄 Lizenz

Projekt basiert auf TourDe360/TDV Player. Siehe entsprechende Lizenzbestimmungen in den lib-Ordnern.