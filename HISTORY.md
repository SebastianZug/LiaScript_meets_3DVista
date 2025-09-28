# 📝 Changelog

## Version 1.6 (2025-09-28) - GitHub Pages PDF-Download-Fix 🌐📄
- 🎯 **Kritisches GitHub Pages Problem gelöst** - PDFs funktionieren jetzt online
- 🔧 **3DVista downloadFile()-Funktion repariert** in `data/script.js`
  - Problem: Relative URLs (`data/files/...`) werden von GitHub Pages Security-Policies blockiert
  - Lösung: Automatische Konvertierung zu absoluten URLs vor Download
  - Technik: Programmatische Click-Events auf `<a>`-Tags mit korrekten href-Attributen
- ✅ **Alle Browser unterstützt** (Chrome, Safari, Firefox)
- ✅ **Lokale Funktionalität erhalten** - Funktioniert weiterhin offline
- ✅ **Diagnostik-Tools entwickelt:**
  - `test_github_pdf.html`: Comprehensive PDF-Funktionalität-Tests
  - Direkte URL-Tests, iframe-Embedding, JavaScript-Simulation
- 🚀 **Deployment-Prozess dokumentiert** mit vollständiger Fehleranalyse
- 🎯 **Ergebnis:** 3DVista-Tour ist jetzt vollständig GitHub Pages kompatibel

## Version 1.5 (2025-09-28) - PDF-Download-Fehlerbehebung (Lokal) 📄✅
- ✅ **Kritisches PDF-Problem behoben** - Alle Downloads funktionieren jetzt
- ✅ **JavaScript openLink-Funktion korrigiert** in `data/script.js`
  - Entfernt: Automatisches Hinzufügen von führenden Slashes bei `data/files/`-Pfaden
  - Problem: `data/files/Anleitung_Arduino_de.pdf` wurde zu `/data/files/Anleitung_Arduino_de.pdf`
- ✅ **Lokalisierungsdateien repariert:**
  - `locale/de.txt`: Alle PopupPDFBehaviour URLs von `files/` zu `data/files/` korrigiert
  - `data/locale/de.txt`: Identische Korrekturen angewendet
- ✅ **6 PDF-Dokumente validiert und funktionsfähig:**
  - Anleitung_Arduino_de.pdf (6.5 MB)
  - Praktikumsanleitung_Teil1_Einführung&Grundlagen_de.pdf
  - Anleitung_Regelkreis_SS2024_de.pdf
  - Anleitung_DM_WiSe2023_2024_de.pdf
  - Excel_Datenstreamer_SS2023_de.pdf  
  - 2022-11-04_Anleitung_MK_R04_de.pdf
- ✅ **Test-Tools entwickelt:**
  - `test_downloads.html`: Allgemeine PDF-Download-Tests
  - `test_arduino.html`: Spezifische Tests für problematische Dateien
- ✅ **Debugging-Prozess dokumentiert** in CHANGES.md
- 🎯 **Ergebnis:** Tour ist jetzt vollständig produktionsreif für Studenten

## Version 1.4 (2025-09-28) - Video-Optimierung für GitHub 🎬
- ✅ **Video-Komprimierung** für GitHub-Kompatibilität implementiert
- ✅ **Große Video-Dateien optimiert:**
  - `video_E17BD4A8_EFB0_B84B_41E6_605C90C38D70_de.mp4`: 69MB → 8.6MB (87% kleiner)
  - `video_E17C4894_EFB0_A85B_41D2_55B57A1D5BA5_de.mp4`: 48MB → 5.7MB (88% kleiner)
  - `video_FFB71EED_EFB0_A9C4_41CA_B9348FB454A7_de.mp4`: 44MB → 4.5MB (90% kleiner)
- ✅ **FFmpeg H.264-Komprimierung** mit optimierten Einstellungen
- ✅ **Repository-Größe reduziert** für bessere GitHub-Performance
- ✅ **Video-Qualität beibehalten** bei deutlich kleinerer Dateigröße

## Version 1.3 (2025-09-28) - LiaScript Integration & Dokumentationsstruktur 📚
- ✅ **LiaScript-Integration** vollständig implementiert
- ✅ **README.md als LiaScript-Dokument** konfiguriert mit LiaScript-Badge
- ✅ **Drei-Dateien-Struktur** eingeführt für bessere Dokumentation:
  - `README.md` - Projekt-Einstieg und LiaScript-Integration
  - `CHANGES.md` - Detaillierte technische Dokumentation
  - `HISTORY.md` - Versionsverlauf und Changelog
- ✅ **LiaScript-Demo** direkt in README.md eingebettet
- ✅ **Interaktive 3DVista-Tour** über LiaScript-Syntax aufrufbar
- ✅ Performance-Hinweise und Geräte-Kompatibilität dokumentiert
- ✅ Strukturierte Dokumentation nach Open-Source-Standards

## Version 1.2 (2025-09-28) - GitHub Pages Ready 🌐
- ✅ **GitHub Pages Deployment** konfiguriert und live
- ✅ `index.htm` → `index.html` umbenannt
- ✅ `.nojekyll`-Datei hinzugefügt
- ✅ **Live-URL verfügbar:** https://sebastianzug.github.io/LiaScript_meets_3DVista/
- ✅ Repository vollständig dokumentiert
- ✅ Deployment-Anweisungen hinzugefügt

## Version 1.1 (2025-09-28) - Lokale Fixes
- ✅ Alle Pfad-Probleme behoben
- ✅ PDF.js vollständig konfiguriert  
- ✅ Symbolische Links für Kompatibilität
- ✅ Cache-Busting implementiert
- ✅ Deutsche Lokalisierung korrigiert
- ✅ Mobile/Desktop-Skripte repariert

## Version 1.0 (Original Export)
- 🔴 Absolute Pfade (nicht funktionsfähig)
- 🔴 Fehlende PDF.js-Konfiguration
- 🔴 Gebrochene Locale-Pfade