---
name: Project Axis
description: Student-built maker site — breadboard-zine energy, lab notebook soul, built not designed.
colors:
  hot-orange: "#e55c0a"
  amber-yellow: "#f0a800"
  workshop-parchment: "#f6f4ef"
  parchment-secondary: "#f2efe9"
  deep-ink: "#1c1b19"
  ink-secondary: "#625d54"
  ink-tertiary: "#9c9184"
  status-green: "#2f8f5b"
  status-teal: "#1f7a72"
  slate-tag: "#33475b"
  burgundy-tag: "#8a3a3a"
typography:
  display:
    fontFamily: "Rubik, sans-serif"
    fontSize: "clamp(3rem, 8vw, 6rem)"
    fontWeight: 900
    lineHeight: 1
    letterSpacing: "-0.04em"
  headline:
    fontFamily: "Rubik, sans-serif"
    fontSize: "clamp(1.7rem, 4.5vw, 2.8rem)"
    fontWeight: 900
    lineHeight: 1.1
    letterSpacing: "-0.035em"
  title:
    fontFamily: "Rubik, sans-serif"
    fontSize: "17px"
    fontWeight: 800
    lineHeight: 1.2
    letterSpacing: "-0.02em"
  body:
    fontFamily: "Rubik, sans-serif"
    fontSize: "15px"
    fontWeight: 400
    lineHeight: 1.72
  label:
    fontFamily: "'Geist Mono', ui-monospace, monospace"
    fontSize: "10px"
    fontWeight: 700
    letterSpacing: "0.1em"
rounded:
  sm: "4px"
  md: "6px"
  lg: "10px"
  xl: "14px"
  pill: "100px"
spacing:
  xs: "8px"
  sm: "16px"
  md: "24px"
  lg: "48px"
  xl: "72px"
  section: "90px"
components:
  button-primary:
    backgroundColor: "{colors.deep-ink}"
    textColor: "{colors.workshop-parchment}"
    rounded: "{rounded.sm}"
    padding: "12px 24px"
  button-primary-hover:
    backgroundColor: "{colors.hot-orange}"
    textColor: "{colors.workshop-parchment}"
    rounded: "{rounded.sm}"
    padding: "12px 24px"
  button-hero:
    backgroundColor: "{colors.workshop-parchment}"
    textColor: "{colors.deep-ink}"
    rounded: "{rounded.sm}"
    padding: "16px 32px"
  button-hero-hover:
    backgroundColor: "{colors.workshop-parchment}"
    textColor: "{colors.hot-orange}"
    rounded: "{rounded.sm}"
    padding: "16px 32px"
  tag-orange:
    backgroundColor: "#fef0e8"
    textColor: "{colors.hot-orange}"
    rounded: "{rounded.sm}"
    padding: "3px 10px"
  tag-green:
    backgroundColor: "#e6f4ec"
    textColor: "{colors.status-green}"
    rounded: "{rounded.sm}"
    padding: "3px 10px"
---

# Design System: Project Axis

## 1. Overview

**Creative North Star: "The Breadboard Zine"**

Project Axis looks like it was made by the people who actually built the thing. That's the point. The visual language borrows from photocopied maker zines, lab notebooks with sticky notes, and the honest chaos of a breadboard mid-project: component labels over hand-drawn grids, caution-tape yellow against workshop-parchment cream, stamps that land a few pixels off-center and are better for it. There is no aspirational polish here. There is only real work, documented.

The site exists in the register of makers who build things with their hands and document them for other makers. It is not a pitch deck. It is not a portfolio for art directors. The typography is massive and heavy because confidence is earned, not designed. The shadows are hard-offset and directional because they look stamped, not rendered. The grid background is always present because graph paper is the universal surface of prototyping.

This system explicitly rejects: AI-generated startup landing pages (hero metric grids, gradient text, glassmorphism, identical card grids), Apple-minimalism (too expensive-feeling, wrong register), flat/bland SaaS cream (generic, signals nothing), and corporate pitch decks rendered as HTML.

**Key Characteristics:**
- Hard offset box-shadows, never Gaussian or ambient
- Massive 900-weight display type with tight negative letter-spacing
- Geist Mono labels with `//` prefix eyebrows — every section is labeled like a schematic
- Warm cream grid background (28px, ink-tinted) as the universal canvas
- Dark ink (`#1c1b19`) sections create high-contrast banding — ink on parchment, like a print run
- Color is earned, not sprayed: tags and accent marks, not washes

## 2. Colors: The Zine Palette

Warm, printed, never clinical. The palette reads like a well-used workshop: copper traces, amber filament, pressed ink, aged parchment.

### Primary
- **Hot Orange** (`#e55c0a`): The primary action color and the brand signature. Hot solder, safety orange, PCB silkscreen. Used on eyebrow labels, primary buttons (hover state), borders on featured elements, section accents, and the invest amount figure. Applied sparingly — it marks things that matter.
- **Amber Yellow** (`#f0a800`): Caution-tape yellow. The color of a PCB silkscreen warning label, a filament bulb in a dark workshop. Used on stat values in dark sections, circuit-path labels, "in-progress" badges, and // prefix marks. Sits clearly distinct from Hot Orange — warmer, lighter, used for annotation rather than action.

### Secondary
- **Status Green** (`#2f8f5b`): Completion. "Done" badges on accordion items, success states. Used on ≤2% of any screen.
- **Status Teal** (`#1f7a72`): Environmental/air-quality project tag. Also used for `Environment` category labels.
- **Slate Tag** (`#33475b`): AI/Vision category. The coldest color in the palette; used only for the SoundView project tag.
- **Burgundy Tag** (`#8a3a3a`): Team/person category. Reserved, warm, subdued.

### Neutral
- **Workshop Parchment** (`#f6f4ef`): The universal surface. Every page background, every card face. Always carries the 28px ink-grid overlay.
- **Parchment Secondary** (`#f2efe9`): Slightly warmer, used for hover surfaces and secondary backgrounds.
- **Deep Ink** (`#1c1b19`): Full-bleed dark sections (stats strip, team section, footer). Printing press black with a warm tint. Also used for primary button fills at rest.
- **Ink Secondary** (`#625d54`): Body text and descriptive copy on parchment.
- **Ink Tertiary** (`#9c9184`): Captions, timestamps, metadata.

### Named Rules
**The Earned Color Rule.** Color appears on marks, badges, labels, and CTA elements — not on backgrounds or large fills (except designated dark-ink sections). If a surface needs color to be interesting, the surface needs a better layout.

**The Hot-Orange Ceiling.** Hot Orange touches at most 10% of any given screen's area. Its scarcity is the point. If it's everywhere, it means nothing.

## 3. Typography

**Display/Headline Font:** Rubik (sans-serif, weight 900)
**Body Font:** Rubik (sans-serif, weight 400)
**Label/Mono Font:** Geist Mono (ui-monospace fallback)

**Character:** Rubik at 900 weight with negative letter-spacing reads like silk-screened type on a component label. Heavy, direct, zero decoration. Geist Mono for all labels, eyebrows, and metadata — treating the interface like a schematic where every element is annotated in the same typeface.

### Hierarchy
- **Display** (900, `clamp(3rem, 8vw, 6rem)`, lh 1, ls -0.04em): Page heroes only. The number that fills the screen. Appears once per page.
- **Headline** (900, `clamp(1.7rem, 4.5vw, 2.8rem)`, lh 1.1, ls -0.035em): Section titles (`how-title`, `proj-section-title`). Confident and unambiguous.
- **Title** (800, 17–20px, lh 1.2, ls -0.02em): Card headings, accordion titles, person names.
- **Body** (400, 15px, lh 1.72): Primary prose. Max line length 65ch. The only weight that breathes.
- **Label** (Geist Mono, 700, 10px, ls 0.10em, UPPERCASE): All eyebrows, section markers, badges, and metadata. Always preceded by `//` in eyebrow context. Reads like a datasheet annotation.

### Named Rules
**The // Rule.** Every section eyebrow is prefixed `//`. It is a schematic annotation, not a decorative slash. Do not use it on body text, headings, or anywhere that isn't a label or eyebrow.

**The One-Weight Rule.** Display and Headline are always 900. Title is always 800. Body is always 400. Label is always 700. Never 500 or 600 in heading context. Weight consistency is what makes the scale legible.

## 4. Elevation

This system uses **hard offset box-shadows only**. No Gaussian blur, no ambient diffusion, no `drop-shadow` filters. Every shadow is directional: X offset matches Y offset, referencing a light source at top-left. Shadows exist to make things feel physically pressed or stamped onto the surface.

### Shadow Vocabulary
- **Stamp** (`2px 2px 0 rgba(28, 27, 25, 0.15)`): Default resting state for cards and form elements. Barely perceptible — the element is on the surface.
- **Lifted** (`4px 4px 0 rgba(28, 27, 25, 0.18)`): Hover state. The element has been picked up slightly.
- **Pressed** (`6px 6px 0 rgba(28, 27, 25, 0.20)`): Focus or active state on prominent elements. Maximum depth in this system.

Hover behavior pairs the shadow with a directional translate: `transform: translate(-2px, -3px)`. This moves the element toward the light source as the shadow grows, making it feel like it's actually lifting off the surface.

### Named Rules
**The No-Blur Rule.** If a shadow has a blur radius greater than 0, it is wrong. Rewrite it. This system has no ambient glow, no soft diffusion, no vignette. Only stamps.

**The Directional Law.** Shadows always go down-right (`2px 2px 0` / `4px 4px 0` / `6px 6px 0`). No inset shadows, no top-right or bottom-left variants. The light source is fixed.

## 5. Components

### Buttons
Blunt, legible, confident. No rounding beyond what removes the sharp machine edge.

- **Shape:** Gently squared (4px radius). Never pill-shaped, never fully rounded.
- **Primary (rest):** Deep Ink fill (`#1c1b19`), Workshop Parchment text. Stamp shadow. 12px/24px padding. Uppercase Geist Mono label, 0.05em letter-spacing.
- **Primary (hover):** Translate `(-2px, -3px)`, Lifted shadow. Background shifts to Hot Orange.
- **Hero CTA:** Workshop Parchment fill, Deep Ink text. Same hover behavior. Used on carousel overlays over dark imagery.
- **Read More / Secondary:** No fill, 1.5px Deep Ink border. Same shape and sizing. Hover: fill with Parchment Secondary.

### Project Tags / Chips
- **Style:** Colored text on tinted background (e.g. Hot Orange text on `#fef0e8`, Green on `#e6f4ec`). 1px matching border. 3px / 10px padding. 4px radius.
- **No hover state.** Tags are informational, not interactive.

### Cards
The card is not the default. When cards appear, they earn their container.

- **Corner Style:** 6px radius (slightly more than buttons — not the same shape).
- **Background:** Workshop Parchment (`#f6f4ef` or `#faf9f5`).
- **Shadow:** Stamp at rest, Lifted on hover. Always paired with `translate(-2px, -3px)` on hover.
- **Border:** 1.5px, `rgba(28, 27, 25, 0.10)`.
- **Internal Padding:** 22–28px.
- **Never nest cards.** A card inside a card is a layout failure.

### Accordion / Blog Entries
- **WIP state:** Left border amber (`#c98a2b`), light amber background (`#fdf5e4`). Badge: `WIP` in amber mono.
- **Done state:** Left border green (`#2f8f5b`), light green background. Badge: `Completed` in green mono.
- **Open panel:** Slides open. Inner content uses `blog-panel` styling: 15px padding, body text at 14px / lh 1.78, images full-width with 8px radius.

### FAQ Items
- `<details>` / `<summary>` native elements. No JavaScript.
- **Rest:** Cream background, 1.5px border, Stamp shadow.
- **Open:** Stamp shadow becomes Lifted, `translate(-1px, -2px)`. The `+` rotates 45deg to form `×`.
- **Summary:** 600 weight, 15px, ink primary. No underline.

### Navigation
- **Style:** Sticky, `rgba(246, 244, 239, 0.92)` backdrop with 20px blur. 1px ink border at bottom. Slides in from top on load (60ms ease animation).
- **Links:** Geist Mono, 11px, uppercase, 0.08em letter-spacing. Underline on hover via `::after` pseudo-element that scales from 0 to 1.
- **Logo:** 50×50px. Wrapped in `<a>` to home. Always present.
- **Mobile:** Hamburger at 768px. Mobile menu full-screen overlay at `rgba(246, 244, 239, 0.98)`.

### Schematic Eyebrow (Signature Component)
The site's most distinctive recurring element. Appears before every major section.

- **Structure:** `<p class="projects-eyebrow">` — Geist Mono, 10–11px, uppercase, Hot Orange, 0.08em letter-spacing.
- **`//` prefix:** Applied via `::before { content: "//"; margin-right: 6px; opacity: 0.5; }`. The slashes are always dimmer than the text.
- **Usage:** One per section, above the section headline. Never on body text. Never styled differently across pages.

## 6. Do's and Don'ts

### Do:
- **Do** use hard offset box-shadows only (`2px 2px 0` / `4px 4px 0` / `6px 6px 0`). No blur, no ambient glow.
- **Do** pair hover shadows with directional translate (`translate(-2px, -3px)`) — the element moves toward the light source.
- **Do** prefix every section eyebrow with `//` via CSS `::before`. It is schematic annotation, not decoration.
- **Do** use Geist Mono for all labels, badges, timestamps, and metadata — it reads like a datasheet.
- **Do** write display headings at weight 900 with `letter-spacing: -0.04em`. Scale is meaningless without weight.
- **Do** keep Hot Orange (`#b3541e`) on ≤10% of any screen — marks, labels, CTAs only.
- **Do** use the 28px grid background on every page surface. It is the graph-paper substrate of every prototype.
- **Do** show real photos, real measurements, real component names. Authenticity over illustration.
- **Do** use `<details>` / `<summary>` for FAQ and accordion items — native, no JavaScript, accessible.

### Don't:
- **Don't** use gradient text (`background-clip: text` with a gradient). It is prohibited by this system. This includes `.invest-amount` — fix it to a solid color.
- **Don't** use Gaussian or ambient shadows. If `box-shadow` has a blur radius greater than 0, it is wrong.
- **Don't** use glassmorphism — blur cards, frosted containers, or decorative backdrop-filter use on anything except the sticky navbar.
- **Don't** use the hero-metric template (big number, small label, supporting stats). This site's stats strip is dark ink and earns its numbers with real context, not SaaS decoration.
- **Don't** build identical card grids where every card is the same shape, same image slot, same text pattern. Vary the affordance to fit the content.
- **Don't** use inline `style=""` for colors. Every color value must come from a CSS custom property. Inline color hacks break dark-ink sections and future palette updates.
- **Don't** use `border-left` or `border-right` greater than 1px as a colored accent stripe on cards or list items. Use full borders, background tints, or leading numbers instead.
- **Don't** add copy that restates the heading. If the heading is "Our Team", the first paragraph must not say "Here you can meet our team." Cut it.
- **Don't** use emoji as icons. Use SVG. The site targets screen-reader users directly; emoji have inconsistent accessible names.
- **Don't** make the design feel "finished." Slightly raw is the point.
