<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>UCAO-TECH | TRC 2025</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css">
    <link href="https://fonts.googleapis.com/css2?family=Orbitron:wght@400;500;700;900&family=Roboto:wght@300;400;500;700&display=swap" rel="stylesheet">
    <style>
        :root {
            --primary: #0a192f;
            --secondary: #00d1ff;
            --accent: #ff2e63;
            --light: #e6f1ff;
            --dark: #020c1b;
            --success: #2ecc71;
            --cyber-blue: #00f7ff;
            --cyber-purple: #9452ff;
        }
        
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }
        
        body {
            background-color: var(--dark);
            color: var(--light);
            font-family: 'Roboto', sans-serif;
            overflow-x: hidden;
            line-height: 1.6;
        }
        
        h1, h2, h3, h4, .logo, .nav-links a {
            font-family: 'Orbitron', sans-serif;
            letter-spacing: 1px;
        }
        
        /* Animations */
        @keyframes fadeIn {
            from { opacity: 0; transform: translateY(20px); }
            to { opacity: 1; transform: translateY(0); }
        }
        
        @keyframes float {
            0% { transform: translateY(0px); }
            50% { transform: translateY(-15px); }
            100% { transform: translateY(0px); }
        }
        
        @keyframes pulse {
            0% { opacity: 0.5; }
            50% { opacity: 1; }
            100% { opacity: 0.5; }
        }
        
        @keyframes scanline {
            0% { transform: translateY(-100%); }
            100% { transform: translateY(100%); }
        }
        
        @keyframes glitch {
            0% { transform: translate(0); }
            20% { transform: translate(-3px, 3px); }
            40% { transform: translate(-3px, -3px); }
            60% { transform: translate(3px, 3px); }
            80% { transform: translate(3px, -3px); }
            100% { transform: translate(0); }
        }
        
        /* Cyber UI Elements */
        .cyber-box {
            position: relative;
            border: 2px solid var(--secondary);
            box-shadow: 0 0 15px rgba(0, 209, 255, 0.5);
            background-color: rgba(10, 25, 47, 0.7);
            backdrop-filter: blur(5px);
            overflow: hidden;
        }
        
        .cyber-box::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: linear-gradient(
                45deg,
                transparent 48%,
                var(--secondary) 49%,
                var(--secondary) 51%,
                transparent 52%
            );
            background-size: 10px 10px;
            opacity: 0.1;
            pointer-events: none;
        }
        
        .cyber-title {
            position: relative;
            display: inline-block;
            color: var(--cyber-blue);
            text-shadow: 0 0 10px rgba(0, 247, 255, 0.7);
        }
        
        .cyber-title::after {
            content: '';
            position: absolute;
            bottom: -5px;
            left: 0;
            width: 100%;
            height: 2px;
            background: linear-gradient(90deg, var(--secondary), var(--cyber-purple));
            box-shadow: 0 0 10px var(--secondary);
        }
        
        /* Header */
        header {
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            z-index: 1000;
            background-color: rgba(2, 12, 27, 0.9);
            backdrop-filter: blur(10px);
            border-bottom: 1px solid rgba(0, 209, 255, 0.2);
            transition: all 0.3s ease;
        }
        
        .navbar {
            display: flex;
            justify-content: space-between;
            align-items: center;
            max-width: 1400px;
            margin: 0 auto;
            padding: 1rem 2rem;
        }
        
        .logo {
            display: flex;
            align-items: center;
            gap: 15px;
            color: white;
            text-decoration: none;
            font-size: 1.5rem;
            font-weight: 700;
        }
        
        .logo img {
            height: 50px;
            transition: transform 0.5s ease;
        }
        
        .logo:hover img {
            transform: rotate(360deg);
        }
        
        .logo span {
            color: var(--secondary);
        }
        
        .nav-links {
            display: flex;
            gap: 1.5rem;
        }
        
        .nav-links a {
            color: rgba(230, 241, 255, 0.8);
            text-decoration: none;
            font-weight: 500;
            font-size: 0.82rem;
            text-transform: uppercase;
            letter-spacing: 1.2px;
            padding: 0.5rem 0.8rem;
            position: relative;
            transition: all 0.3s ease;
        }
        
        .nav-links a::before {
            content: '';
            position: absolute;
            bottom: 0;
            left: 0;
            width: 0;
            height: 2px;
            background: linear-gradient(90deg, var(--secondary), var(--cyber-purple));
            transition: width 0.3s ease;
        }
        
        .nav-links a:hover {
            color: var(--cyber-blue);
        }
        
        .nav-links a:hover::before {
            width: 100%;
        }
        
        .nav-links a.active {
            color: var(--cyber-blue);
        }
        
        .nav-links a.active::before {
            width: 100%;
        }
        
        .mobile-menu-btn {
            display: none;
            background: none;
            border: none;
            color: white;
            font-size: 1.5rem;
            cursor: pointer;
            z-index: 1001;
        }
        
        /* Hero Section */
        .hero {
            height: 100vh;
            position: relative;
            overflow: hidden;
            display: flex;
            align-items: center;
            padding: 0 2rem;
        }
        
        .hero-video-container {
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            overflow: hidden;
            z-index: -1;
        }
        
        .hero-video {
            width: 100%;
            height: 100%;
            object-fit: cover;
            opacity: 0.3;
        }
        
        .hero-overlay {
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: linear-gradient(
                to bottom,
                rgba(2, 12, 27, 0.8) 0%,
                rgba(10, 25, 47, 0.5) 50%,
                rgba(2, 12, 27, 0.8) 100%
            );
            z-index: -1;
        }
        
        .hero-content {
            max-width: 1400px;
            margin: 0 auto;
            width: 100%;
            padding-top: 80px;
            animation: fadeIn 1s ease-out;
        }
        
        .hero-text {
            max-width: 800px;
        }
        
        .hero h1 {
            font-size: 3.5rem;
            margin-bottom: 1.5rem;
            line-height: 1.2;
            background: linear-gradient(90deg, var(--cyber-blue), var(--light));
            -webkit-background-clip: text;
            background-clip: text;
            color: transparent;
            text-shadow: 0 0 15px rgba(0, 247, 255, 0.3);
        }
        
        .hero p {
            font-size: 1.2rem;
            margin-bottom: 2.5rem;
            opacity: 0.9;
            max-width: 700px;
        }
        
        .hero-cta {
            display: flex;
            gap: 1.5rem;
        }
        
        .btn {
            padding: 0.9rem 2.5rem;
            border-radius: 0;
            font-weight: 600;
            text-decoration: none;
            transition: all 0.3s ease;
            cursor: pointer;
            font-size: 0.95rem;
            letter-spacing: 1.5px;
            text-transform: uppercase;
            position: relative;
            overflow: hidden;
            border: none;
            font-family: 'Orbitron', sans-serif;
        }
        
        .btn-primary {
            background-color: transparent;
            color: var(--cyber-blue);
            border: 2px solid var(--secondary);
            box-shadow: 0 0 15px rgba(0, 209, 255, 0.3);
        }
        
        .btn-primary:hover {
            background-color: rgba(0, 209, 255, 0.1);
            box-shadow: 0 0 30px rgba(0, 209, 255, 0.6);
            transform: translateY(-3px);
        }
        
        .btn-primary::before {
            content: '';
            position: absolute;
            top: 0;
            left: -100%;
            width: 100%;
            height: 100%;
            background: linear-gradient(
                90deg,
                transparent,
                rgba(0, 209, 255, 0.2),
                transparent
            );
            transition: 0.5s;
        }
        
        .btn-primary:hover::before {
            left: 100%;
        }
        
        .btn-outline {
            background-color: transparent;
            color: white;
            border: 2px solid white;
        }
        
        .btn-outline:hover {
            background-color: rgba(255, 255, 255, 0.1);
            box-shadow: 0 0 30px rgba(255, 255, 255, 0.3);
            transform: translateY(-3px);
        }
        
        /* Circuit Animation */
        .circuit-animation {
            position: absolute;
            width: 100%;
            height: 100%;
            top: 0;
            left: 0;
            z-index: -1;
            opacity: 0.1;
        }
        
        .circuit-line {
            position: absolute;
            background-color: var(--secondary);
            box-shadow: 0 0 5px var(--secondary);
        }
        
        /* About Section */
        .section {
            padding: 6rem 2rem;
            position: relative;
            overflow: hidden;
        }
        
        .section-container {
            max-width: 1400px;
            margin: 0 auto;
            position: relative;
        }
        
        .section-title {
            text-align: center;
            margin-bottom: 5rem;
            position: relative;
        }
        
        .section-title h2 {
            font-size: 2.8rem;
            display: inline-block;
            position: relative;
            padding-bottom: 1rem;
        }
        
        .section-title p {
            max-width: 700px;
            margin: 1.5rem auto 0;
            font-size: 1.1rem;
        }
        
        .about-content {
            display: flex;
            align-items: center;
            gap: 4rem;
            flex-wrap: wrap;
        }
        
        .about-text {
            flex: 1;
            min-width: 300px;
        }
        
        .about-text h3 {
            font-size: 2rem;
            margin-bottom: 1.5rem;
            line-height: 1.3;
        }
        
        .about-text p {
            margin-bottom: 1.5rem;
            font-size: 1.1rem;
        }
        
        .about-image {
            flex: 1;
            min-width: 300px;
            max-width: 600px;
            position: relative;
            border-radius: 5px;
            overflow: hidden;
            box-shadow: 0 0 30px rgba(0, 209, 255, 0.2);
            display: flex;
            align-items: center;
            justify-content: center;
            background: rgba(10, 25, 47, 0.7);
            margin: 0 auto;
        }
        
        .about-image video, .about-image iframe {
            width: 100%;
            max-width: 600px;
            height: 315px;
            border-radius: 5px;
            box-shadow: 0 0 30px rgba(0, 209, 255, 0.2);
            display: block;
            background: #000;
        }
        
        /* Features Section */
        .features-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(350px, 1fr));
            gap: 2.5rem;
            margin-top: 3rem;
        }
        
        .feature-card {
            position: relative;
            padding: 3rem 2rem;
            transition: all 0.5s ease;
            border: 1px solid rgba(0, 209, 255, 0.2);
            background-color: rgba(10, 25, 47, 0.5);
            backdrop-filter: blur(5px);
            overflow: hidden;
        }
        
        .feature-card:hover {
            transform: translateY(-10px);
            box-shadow: 0 10px 30px rgba(0, 209, 255, 0.2);
            border-color: var(--secondary);
        }
        
        .feature-card::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: linear-gradient(
                45deg,
                transparent 48%,
                var(--secondary) 49%,
                var(--secondary) 51%,
                transparent 52%
            );
            background-size: 10px 10px;
            opacity: 0.1;
            pointer-events: none;
        }
        
        .feature-icon {
            width: 80px;
            height: 80px;
            background: linear-gradient(135deg, var(--secondary), var(--cyber-purple));
            border-radius: 50%;
            display: flex;
            align-items: center;
            justify-content: center;
            margin: 0 auto 2rem;
            font-size: 2rem;
            box-shadow: 0 0 20px rgba(0, 209, 255, 0.5);
        }
        
        .feature-card h3 {
            font-size: 1.5rem;
            margin-bottom: 1.5rem;
            text-align: center;
            color: var(--cyber-blue);
        }
        
        .feature-card p {
            text-align: center;
            opacity: 0.9;
            line-height: 1.8;
        }
        
        /* Team Section */
        .team-members {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(180px, 1fr));
            gap: 2.2rem;
            justify-items: center;
            align-items: start;
        }
        
        .member-card {
            position: relative;
            overflow: hidden;
            transition: all 0.5s ease;
            border: 1px solid rgba(0, 209, 255, 0.2);
            background-color: rgba(10, 25, 47, 0.5);
        }
        
        .member-card:hover {
            transform: translateY(-10px);
            box-shadow: 0 10px 30px rgba(0, 209, 255, 0.3);
            border-color: var(--secondary);
        }
        
        .member-image {
            height: 350px;
            overflow: hidden;
            position: relative;
        }
        
        .member-image img {
            width: 100%;
            height: 100%;
            object-fit: cover;
            transition: transform 0.5s ease;
        }
        
        .member-card:hover .member-image img {
            transform: scale(1.1);
        }
        
        .member-info {
            padding: 2rem;
            text-align: center;
            position: relative;
        }
        
        .member-info h3 {
            font-size: 1.4rem;
            margin-bottom: 0.5rem;
            color: white;
        }
        
        .member-info p {
            color: var(--secondary);
            font-weight: 600;
            margin-bottom: 1.5rem;
            font-size: 0.9rem;
            text-transform: uppercase;
            letter-spacing: 1px;
        }
        
        .social-links {
            display: flex;
            justify-content: center;
            gap: 1rem;
        }
        
        .social-links a {
            color: white;
            background-color: rgba(0, 209, 255, 0.1);
            width: 40px;
            height: 40px;
            border-radius: 50%;
            display: flex;
            align-items: center;
            justify-content: center;
            transition: all 0.3s ease;
            border: 1px solid rgba(0, 209, 255, 0.3);
        }
        
        .social-links a:hover {
            background-color: var(--secondary);
            color: var(--dark);
            transform: translateY(-3px);
            box-shadow: 0 5px 15px rgba(0, 209, 255, 0.5);
        }
        
        /* Footer moderne, marges et espaces réduits */
        footer {
            background: linear-gradient(120deg, #0a192f 60%, #001a2e 100%);
            color: #e6f1ff;
            padding: 1.2rem 0 0.5rem 0;
            border-top: 2px solid #00d1ff22;
        }
        
        .footer-grid {
            max-width: 1250px;
            margin: 0 auto;
            display: flex;
            flex-wrap: wrap;
            align-items: flex-start;
            justify-content: space-between;
            gap: 1.2rem;
        }
        
        @media (max-width: 1050px) {
            .footer-grid {
                flex-direction: column !important;
                align-items: center !important;
                gap: 0.7rem !important;
            }
        }
        
        /* Back to Top Button */
        .back-to-top {
            position: fixed;
            bottom: 30px;
            right: 30px;
            background: linear-gradient(135deg, var(--secondary), var(--cyber-purple));
            color: var(--dark);
            width: 60px;
            height: 60px;
            border-radius: 50%;
            display: flex;
            align-items: center;
            justify-content: center;
            font-size: 1.5rem;
            cursor: pointer;
            opacity: 0;
            visibility: hidden;
            transition: all 0.3s ease;
            z-index: 999;
            box-shadow: 0 0 20px rgba(0, 209, 255, 0.5);
            border: none;
        }
        
        .back-to-top.active {
            opacity: 1;
            visibility: visible;
        }
        
        .back-to-top:hover {
            transform: translateY(-5px) scale(1.1);
            box-shadow: 0 0 30px rgba(0, 209, 255, 0.8);
        }
        
        /* Responsive Design */
        @media (max-width: 1200px) {
            .hero h1 {
                font-size: 3rem;
            }
        }
        
        @media (max-width: 992px) {
            .hero h1 {
                font-size: 2.5rem;
            }
            
            .section {
                padding: 5rem 2rem;
            }
            
            .section-title h2 {
                font-size: 2.4rem;
            }
        }
        
        @media (max-width: 768px) {
            .nav-links {
                position: fixed;
                top: 0;
                right: -100%;
                width: 280px;
                height: 100vh;
                background-color: var(--primary);
                flex-direction: column;
                align-items: flex-start;
                justify-content: center;
                gap: 2rem;
                padding: 0 2rem;
                transition: all 0.5s ease;
                backdrop-filter: blur(10px);
                border-left: 1px solid rgba(0, 209, 255, 0.2);
            }
            
            .nav-links.active {
                right: 0;
            }
            
            .mobile-menu-btn {
                display: block;
            }
            
            .hero h1 {
                font-size: 2.2rem;
            }
            
            .hero p {
                font-size: 1rem;
            }
            
            .hero-cta {
                flex-direction: column;
                gap: 1rem;
            }
            
            .btn {
                width: 100%;
                text-align: center;
            }
            
            .about-content {
                flex-direction: column;
            }
            
            .feature-card, .progress-step {
                min-width: 100%;
            }
        }
        
        @media (max-width: 576px) {
            .section {
                padding: 4rem 1.5rem;
            }
            
            .section-title h2 {
                font-size: 2rem;
            }
            
            .hero h1 {
                font-size: 2rem;
            }
            
            .member-card {
                min-width: 100%;
            }
        }
        
        /* Circuit Board Animation */
        .circuit-board {
            position: absolute;
            width: 100%;
            height: 100%;
            top: 0;
            left: 0;
            z-index: -1;
            opacity: 0.05;
            pointer-events: none;
        }
        
        .circuit-path {
            stroke: var(--secondary);
            stroke-width: 1;
            fill: none;
            stroke-dasharray: 1000;
            stroke-dashoffset: 1000;
            animation: dash 20s linear infinite;
        }
        
        @keyframes dash {
            to {
                stroke-dashoffset: 0;
            }
        }
        
        /* Glitch Effect */
        .glitch-effect {
            position: relative;
        }
        
        .glitch-effect::before, .glitch-effect::after {
            content: attr(data-text);
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            opacity: 0.8;
        }
        
        .glitch-effect::before {
            color: var(--cyber-purple);
            z-index: -1;
            animation: glitch 2s infinite;
        }
        
        .glitch-effect::after {
            color: var(--cyber-blue);
            z-index: -2;
            animation: glitch 3s infinite reverse;
        }
        
        /* Holographic Effect */
        .holographic-card {
            position: relative;
            overflow: hidden;
        }
        
        .holographic-card::before {
            content: '';
            position: absolute;
            top: -50%;
            left: -50%;
            width: 200%;
            height: 200%;
            background: linear-gradient(
                to bottom right,
                rgba(0, 247, 255, 0.1),
                rgba(148, 82, 255, 0.1),
                rgba(0, 247, 255, 0.1)
            );
            transform: rotate(45deg);
            animation: hologram 6s linear infinite;
            pointer-events: none;
        }
        
        @keyframes hologram {
            0% { transform: rotate(45deg) translate(-30%, -30%); }
            100% { transform: rotate(45deg) translate(30%, 30%); }
        }
        
        /* Réduction drastique de la hauteur des cartes membres */
        .member-card.holographic-card {
            max-width: 200px !important;
            min-width: 150px !important;
            margin: 0.7rem auto !important;
            padding: 0.7rem 0.5rem 0.7rem 0.5rem !important;
            display: flex !important;
            flex-direction: column !important;
            align-items: center !important;
            box-shadow: 0 2px 12px #00d1ff22 !important;
            height: auto !important;
        }
        .member-image {
            margin-bottom: 0.3rem !important;
        }
        .member-image img {
            max-width: 60px !important;
            height: 60px !important;
            border-radius: 50%;
            object-fit: cover;
            margin: 0 auto;
            display: block;
        }
        .member-info {
            text-align: center;
            margin: 0 !important;
            padding: 0 !important;
        }
        .member-info h3 {
            margin: 0.2rem 0 0.1rem 0 !important;
            font-size: 1.05rem !important;
        }
        .member-info p {
            margin: 0 0 0.2rem 0 !important;
            font-size: 0.93rem !important;
        }
        .social-links {
            margin: 0.1rem 0 0 0 !important;
            gap: 0.3rem !important;
        }
        .social-links a {
            font-size: 1.05rem !important;
        }
    </style>
</head>
<body>
    <!-- Circuit Board Animation Background -->
    <svg class="circuit-board" viewBox="0 0 1000 1000" preserveAspectRatio="none">
        <path class="circuit-path" d="M100,100 L900,100 L900,900 L100,900 Z M300,300 L700,300 L700,700 L300,700 Z" />
        <path class="circuit-path" d="M200,200 L800,200 L800,800 L200,800 Z M400,400 L600,400 L600,600 L400,600 Z" />
        <path class="circuit-path" d="M100,500 L900,500 M500,100 L500,900" />
        <path class="circuit-path" d="M150,150 L850,850 M850,150 L150,850" />
        <circle class="circuit-path" cx="500" cy="500" r="200" />
    </svg>

    <!-- Header -->
    <header>
        <nav class="navbar">
            <a href="#accueil" class="logo">
                <img src="https://ucaotech.com/wp-content/uploads/2024/10/UCAO-TECH-1.png" alt="UCAO-TECH Logo">
                <span>UCAO-TECH</span>
            </a>
            <ul class="nav-links">
                <li><a href="#accueil">Accueil</a></li>
                <li><a href="#a-propos">À propos</a></li>
                <li><a href="#equipe">Équipe</a></li>
                <li><a href="#contact">Contact</a></li>
                <li><a href="#documentation">Documentation</a></li>
            </ul>
        </nav>
    </header>

    <!-- Hero Section -->
    <section class="hero">
        <div class="hero-video-container">
            <iframe width="100%" height="100%" src="https://www.ecm23.be/wp-content/uploads/2023/09/robot-humanoide.jpg" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen class="hero-video"></iframe>
        </div>
        <div class="hero-overlay"></div>
        <div class="hero-content">
            <div class="hero-text">
                <h1 class="glitch-effect" data-text="TRC 2025">TRC 2025</h1>
                <p><strong>Ensemble, nous inventons la robotique de demain : créativité, audace et excellence pour hisser notre université au sommet de l’innovation lors de la grande finale internationale.</strong></p>
                <div class="hero-cta">
                    <a href="#informatique" class="btn btn-primary">Explorer nos projets</a>
                    <a href="#equipe" class="btn btn-outline">Rencontrer l’équipe</a>
                </div>
            </div>
        </div>
    </section>

    <!-- Section Accueil -->
    <section class="section" id="accueil">
        <div class="section-container">
            <div class="section-title">
                <h1 class="cyber-title">Bienvenue sur le site UCAO-TECH</h1>
                <p><strong>Le TEKBOT Robotics Challenge (TRC 2025)</strong> est bien plus qu’une compétition : c’est un rendez-vous international pour révéler les talents africains en robotique et intelligence artificielle. Le thème 2025, <span style="color:#00d1ff;font-weight:600;">« Résilience Urbaine : Gestion Durable des Déchets »</span>, invite les équipes à imaginer des robots capables de transformer la gestion des déchets dans nos villes, pour un avenir plus propre et durable.</p>
            </div>
            <div style="margin:2.5rem 0 0 0;display:flex;flex-wrap:wrap;gap:2.5rem;align-items:stretch;">
                <div style="flex:1 1 320px;min-width:260px;background:rgba(10,25,47,0.92);border-radius:14px;padding:1.5rem;box-shadow:0 2px 18px #00d1ff22;">
                    <h3 style="color:#00d1ff;margin-bottom:0.7rem;">Objectifs du TRC 2025</h3>
                    <ul style="margin-left:1.2rem;line-height:1.7;">
                        <li>Promouvoir la robotique et l’IA auprès des jeunes talents africains</li>
                        <li>Encourager l’innovation pour relever les défis locaux</li>
                        <li>Favoriser la collaboration et l’apprentissage entre équipes africaines</li>
                        <li>Sensibiliser le public aux sciences et technologies (STEM)</li>
                    </ul>
                </div>
                <div style="flex:2 1 420px;min-width:260px;background:rgba(10,25,47,0.92);border-radius:14px;padding:1.5rem;box-shadow:0 2px 18px #00d1ff22;">
                    <h3 style="color:#00d1ff;margin-bottom:0.7rem;">Un défi, plusieurs épreuves</h3>
                    <ul style="margin-left:1.2rem;line-height:1.7;">
                        <li><strong>Collecte intensive :</strong> Localiser and ramasser efficacement des déchets dans l’arène</li>
                        <li><strong>Tri et organisation :</strong> Classer les déchets collectés selon leur type</li>
                        <li><strong>Distribution ciblée :</strong> Livrer les déchets triés aux bonnes destinations</li>
                        <li><strong>Gestion optimale :</strong> Exploiter au mieux l’énergie et les ressources du robot</li>
                        <li><strong>Respect des règles :</strong> Sécurité, conformité et esprit d’équipe</li>
                    </ul>
                    <div style="background:rgba(0,209,255,0.08);border-left:3px solid #00d1ff;padding:0.7rem 1rem;margin-top:1rem;font-size:0.98rem;">
                        <strong>Un challenge pour inspirer, innover et agir concrètement pour l’Afrique de demain.</strong>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <!-- À propos : Présentation TEKBOT Robotics et esprit du concours -->
    <section class="section" id="a-propos">
        <div class="section-container" style="max-width:1100px;margin:0 auto;">
            <div class="section-title">
                <h2 class="cyber-title">À propos</h2>
            </div>
            <!-- Bloc TEKBOT Robotics / TRC 2025 -->
            <div style="background:rgba(0,209,255,0.07);border-left:4px solid #00d1ff;padding:2rem 2rem 1.5rem 2rem;margin-bottom:2.5rem;border-radius:10px;">
                <h3 style="color:#00d1ff;margin-bottom:1rem;">TEKBOT Robotics & TRC 2025</h3>
                <p style="font-size:1.08rem;line-height:1.8;max-width:900px;margin-bottom:1.2rem;">
                    <strong>TEKBOT Robotics</strong> est une startup DeepTech engagée pour l’innovation, la formation et la démocratisation de la robotique en Afrique. Nous concevons des solutions robotiques de pointe, tout en menant des actions éducatives et associatives pour révéler les talents de demain.<br><br>
                    <span style="color:#00d1ff;">Notre mission : positionner l’Afrique à l’avant-garde de l’innovation technologique, inspirer une nouvelle génération d’innovateurs et rendre la robotique accessible à tous.</span>
                </p>
                <div style="display:flex;flex-wrap:wrap;gap:2.5rem;align-items:stretch;">
                    <div style="flex:1 1 320px;min-width:260px;background:rgba(10,25,47,0.92);border-radius:14px;padding:1.5rem;box-shadow:0 2px 18px #00d1ff22;">
                        <h4 style="color:#00d1ff;margin-bottom:0.7rem;">Nos valeurs</h4>
                        <ul style="margin-left:1.2rem;line-height:1.7;">
                            <li>Innover pour un avenir prometteur</li>
                            <li>Démystifier et promouvoir la robotique au Bénin</li>
                            <li>Accompagner les jeunes talents africains vers l’innovation</li>
                            <li>Favoriser l’inclusion des femmes dans la robotique</li>
                            <li>Créer un environnement propice aux projets robotiques</li>
                        </ul>
                    </div>
                    <div style="flex:2 1 420px;min-width:260px;background:rgba(10,25,47,0.92);border-radius:14px;padding:1.5rem;box-shadow:0 2px 18px #00d1ff22;">
                        <h4 style="color:#00d1ff;margin-bottom:0.7rem;">Le TRC 2025, notre vision</h4>
                        <p>Le TRC 2025 est un tremplin pour révéler les talents africains, encourager l’innovation et sensibiliser à la gestion durable des déchets. C’est aussi un espace d’échange, de collaboration et d’inspiration pour toute la jeunesse du continent.</p>
                    </div>
                </div>
            </div>
            <!-- Bloc équipe UCAO-TECH (mêmes couleurs) -->
            <div style="background:rgba(0,209,255,0.07);border-left:4px solid #00d1ff;padding:2rem 2rem 1.5rem 2rem;border-radius:10px;">
                <h3 style="color:#00d1ff;margin-bottom:1rem;">Notre équipe UCAO-TECH</h3>
                <p style="font-size:1.08rem;line-height:1.8;max-width:900px;margin-bottom:1.2rem;">
                    <strong>Notre équipe UCAO-TECH</strong> s’est fixée pour mission de représenter fièrement l’Afrique de l’Ouest au TRC 2025. Nous visons l’excellence technique, la créativité et l’esprit d’équipe pour décrocher le podium.<br>
                    <span style="color:#00d1ff;">Chaque membre apporte son expertise en informatique, électronique ou mécanique pour relever les défis du concours, dans un esprit de partage, d’excellence et d’innovation.</span>
                </p>
                <div style="display:flex;flex-wrap:wrap;gap:2.5rem;align-items:stretch;">
                    <div style="flex:1 1 320px;min-width:260px;background:rgba(10,25,47,0.92);border-radius:14px;padding:1.5rem;box-shadow:0 2px 18px #00d1ff22;">
                        <h4 style="color:#00d1ff;margin-bottom:0.7rem;">Nos valeurs d’équipe</h4>
                        <ul style="margin-left:1.2rem;line-height:1.7;">
                            <li>Excellence et rigueur</li>
                            <li>Créativité et innovation</li>
                            <li>Partage et transmission</li>
                            <li>Respect et esprit d’équipe</li>
                        </ul>
                    </div>
                    <div style="flex:2 1 420px;min-width:260px;background:rgba(10,25,47,0.92);border-radius:14px;padding:1.5rem;box-shadow:0 2px 18px #00d1ff22;">
                        <h4 style="color:#00d1ff;margin-bottom:0.7rem;">Notre ambition pour le TRC 2025</h4>
                        <p>Être sur le podium, porter haut les couleurs de l’UCAO et de l’Afrique de l’Ouest, et inspirer la prochaine génération d’ingénieurs et de créateurs.</p>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <!-- Features Section (Domaines Techniques) -->
    <section class="section" id="domaines-techniques">
        <div class="section-container">
            <div class="section-title">
                <h2 class="cyber-title">Domaines Techniques</h2>
                <p>Les trois piliers technologiques de notre participation au TRC 2025</p>
            </div>
            <div class="features-grid">
                <div class="feature-card holographic-card">
                    <div class="feature-icon">
                        <i class="fas fa-microchip"></i>
                    </div>
                    <h3>Électronique</h3>
                    <p>Tests sur gyroscope, boîte noire, afficheur 7 segments et autres composants essentiels pour notre robot avec Arduino et KiCad.</p>
                </div>
                
                <div class="feature-card holographic-card">
                    <div class="feature-icon">
                        <i class="fas fa-code"></i>
                    </div>
                    <h3>Informatique</h3>
                    <p>Programmation orientée objet, ROS2, pathfinding et algorithmes avancés pour le contrôle intelligent de notre système robotique.</p>
                </div>
                
                <div class="feature-card holographic-card">
                    <div class="feature-icon">
                        <i class="fas fa-cogs"></i>
                    </div>
                    <h3>Mécanique</h3>
                    <p>Conception et modélisation 3D avec SolidWorks pour des pièces optimisées et un assemblage mécanique performant.</p>
                </div>
            </div>
        </div>
    </section>

    <!-- Section Informatique détaillée -->
    <section class="section" id="informatique">
        <div class="section-container">
            <div class="section-title">
                <h2 class="cyber-title">Informatique</h2>
                <p>Programmation orientée objet, ROS2, pathfinding et autres algorithmes pour le contrôle intelligent de notre système robotique</p>
            </div>
            <div class="about-content">
                <div class="about-text">
                    <h3>Notre approche informatique pour le TRC 2025</h3>
                    <p>Dans le cadre de notre préparation au Tekbot Robotics Challenge 2025, l’équipe informatique adopte une démarche progressive orientée vers l’autonomie et l’intelligence embarquée du robot. Nous utilisons ROS2 comme framework principal pour une communication efficace entre les différents modules.</p>
                    <p>Nos travaux incluent des algorithmes de pathfinding sophistiqués, la programmation orientée objet pour une architecture logicielle modulaire, et l'intégration de divers capteurs pour une perception environnementale précise.</p>
                    <p>L’ensemble de ces travaux fait l’objet d’une documentation continue et d’une validation fonctionnelle, en vue de leur intégration dans le système final.</p>
                    <a href="programmation.html" class="btn btn-primary">Voir la documentation</a>
                </div>
                <div class="about-image holographic-card">
                    <video autoplay muted loop>
                        <source src="https://ucaobenin.rimeiro.com/wp-content/uploads/trc2025/ucaotech-trc2025.mp4" type="video/mp4">
                       
                    </video>
                </div>
            </div>
        </div>
    </section>

    <!-- Section Électronique détaillée -->
    <section class="section" id="electronique">
        <div class="section-container">
            <div class="section-title">
                <h2 class="cyber-title">Électronique</h2>
                <p>Tests sur gyroscope, boîte noire, afficheur 7 segments et autres composants essentiels pour notre robot avec Arduino et KiCad.</p>
            </div>
            <div class="about-content">
                <div class="about-text">
                    <h3>Notre approche électronique pour le TRC 2025</h3>
                    <p>Notre équipe électronique développe des solutions robustes pour la fiabilité et la performance du robot. Nous avons intégré des capteurs, optimisé la gestion de l’alimentation et assuré la sécurité électrique.</p>
                      <ul>
                        <li>Tests sur gyroscope et accéléromètre pour la stabilité et la navigation</li>
                        <li>Développement d’une boîte noire pour la traçabilité</li>
                        <li>Réalisation d’un afficheur 7 segments</li>
                        <li>Utilisation d’Arduino et KiCad pour la conception</li>
                        <li>Respect strict des normes de sécurité et optimisation énergétique</li>
                      </ul>
                      <br>
                    <a href="electronique.html" class="btn btn-primary">Voir la documentation</a>
                </div>
                <div class="about-image holographic-card">
                    <video controls poster="https://ucaotech.com/wp-content/uploads/2024/10/UCAO-TECH-1.png">
                        <source src="https://ucaobenin.rimeiro.com/wp-content/uploads/trc2025/ucaotech-trc2025-electro.mp4" type="video/mp4">
                    </video>
                </div>
            </div>
        </div>
    </section>

    <!-- Section Mécanique détaillée -->
    <section class="section" id="mecanique">
        <div class="section-container">
            <div class="section-title">
                <h2 class="cyber-title">Mécanique</h2>
                <p>Conception et modélisation 3D avec SolidWorks pour des pièces optimisées et un assemblage mécanique performant.</p>
            </div>
            <div class="about-content">
                <div class="about-text">
                    <h3>Notre approche mécanique pour le TRC 2025</h3>
                    <p>L’équipe mécanique conçoit et modélise l’ensemble des pièces du robot pour garantir robustesse, légèreté et facilité d’assemblage. Nous avons utilisé SolidWorks pour la CAO, optimisé la structure pour la compétition et réalisé plusieurs prototypes pour valider la résistance et la fonctionnalité.</p>
                    <ul>
                        <li>Conception 3D de toutes les pièces avec SolidWorks</li>
                        <li>Optimisation du châssis pour la stabilité et la rapidité</li>
                        <li>Prototypage et tests de résistance mécanique</li>
                        <li>Assemblage modulaire pour faciliter la maintenance</li>
                        <li>Respect des contraintes de poids et de dimensions imposées par le règlement</li>
                    </ul>
                    <br>
                    <a href="mecanique.html" class="btn btn-primary">Voir la documentation</a>
                </div>
                <div class="about-image holographic-card">
                    <video controls poster="https://ucaotech.com/wp-content/uploads/2024/10/UCAO-TECH-1.png">
                        <source src="https://ucaobenin.rimeiro.com/wp-content/uploads/trc2025/ucaotech-trc2025-meca.mp4" type="video/mp4">
                    </video>
                </div>
            </div>
        </div>
    </section>

    <!-- Team Section -->
    <section class="section" id="equipe">
        <div class="section-container" style="max-width:1100px;margin:0 auto;">
            <div class="section-title">
                <h2 class="cyber-title">Notre équipe</h2>
            </div>
            <div style="background:rgba(0,209,255,0.07);border-left:4px solid #00d1ff;padding:1.3rem 1.5rem 1.1rem 1.5rem;margin:0 auto 2.2rem auto;max-width:700px;border-radius:10px;text-align:justify;font-size:1.08rem;opacity:0.92;">
                Derrière chaque projet ambitieux, il y a des femmes et des hommes engagés. L’aventure UCAO-TECH, c’est une équipe soudée, des talents complémentaires et une passion commune pour la robotique. Découvrez celles et ceux qui relèvent chaque défi du TRC 2025 avec détermination et créativité.
            </div>
            <div style="display:grid;grid-template-columns:repeat(auto-fit,minmax(160px,1fr));gap:2.2rem;justify-items:center;align-items:start;">
                <!-- Membre 1 -->
                <div style="display:flex;flex-direction:column;align-items:center;background:none;box-shadow:none;padding:0;">
                    <img src="https://randomuser.me/api/portraits/men/23.jpg" alt="KOUASSI Jean" style="width:70px;height:70px;border-radius:50%;object-fit:cover;margin-bottom:0.7rem;border:3px solid #00d1ff;">
                    <span style="display:block;font-size:1.05rem;color:#fff;font-weight:600;margin-bottom:0.2rem;white-space:nowrap;">KOUASSI Jean</span>
                    <p style="margin:0 0 0.5rem 0;font-size:0.93rem;color:#00d1ff;">Pôle Electronique(Chef d’équipe)</p>
                    <div style="display:flex;gap:0.5rem;">
                        <a href="#" style="color:#fff;"><i class="fab fa-linkedin-in"></i></a>
                        <a href="#" style="color:#fff;"><i class="fab fa-github"></i></a>
                        <a href="#" style="color:#fff;"><i class="fas fa-envelope"></i></a>
                    </div>
                </div>
                <!-- Membre 2 -->
                <div style="display:flex;flex-direction:column;align-items:center;background:none;box-shadow:none;padding:0;">
                    <img src="https://randomuser.me/api/portraits/men/45.jpg" alt="AIDASSO David Jonathan" style="width:70px;height:70px;border-radius:50%;object-fit:cover;margin-bottom:0.7rem;border:3px solid #00d1ff;">
                    <span style="display:block;font-size:1.05rem;color:#fff;font-weight:600;margin-bottom:0.2rem;white-space:nowrap;">AIDASSO David Jonathan</span>
                    <p style="margin:0 0 0.5rem 0;font-size:0.93rem;color:#00d1ff;">Pôle IT</p>
                    <div style="display:flex;gap:0.5rem;">
                        <a href="#" style="color:#fff;"><i class="fab fa-linkedin-in"></i></a>
                        <a href="#" style="color:#fff;"><i class="fab fa-github"></i></a>
                        <a href="#" style="color:#fff;"><i class="fas fa-envelope"></i></a>
                    </div>
                </div>
                <!-- Membre 3 -->
                <div style="display:flex;flex-direction:column;align-items:center;background:none;box-shadow:none;padding:0;">
                    <img src="https://randomuser.me/api/portraits/men/67.jpg" alt="ADJAHOU Romance" style="width:70px;height:70px;border-radius:50%;object-fit:cover;margin-bottom:0.7rem;border:3px solid #00d1ff;">
                    <span style="display:block;font-size:1.05rem;color:#fff;font-weight:600;margin-bottom:0.2rem;white-space:nowrap;">ADJAHOU Romance</span>
                    <p style="margin:0 0 0.5rem 0;font-size:0.93rem;color:#00d1ff;">Pôle IT</p>
                    <div style="display:flex;gap:0.5rem;">
                        <a href="#" style="color:#fff;"><i class="fab fa-linkedin-in"></i></a>
                        <a href="#" style="color:#fff;"><i class="fab fa-github"></i></a>
                        <a href="#" style="color:#fff;"><i class="fas fa-envelope"></i></a>
                    </div>
                </div>
                <!-- Membre 4 -->
                <div style="display:flex;flex-direction:column;align-items:center;background:none;box-shadow:none;padding:0;">
                    <img src="https://randomuser.me/api/portraits/men/89.jpg" alt="DOUSSO Ladislas" style="width:70px;height:70px;border-radius:50%;object-fit:cover;margin-bottom:0.7rem;border:3px solid #00d1ff;">
                    <span style="display:block;font-size:1.05rem;color:#fff;font-weight:600;margin-bottom:0.2rem;white-space:nowrap;">DOUSSO Ladislas</span>
                    <p style="margin:0 0 0.5rem 0;font-size:0.93rem;color:#00d1ff;">Pôle IT</p>
                    <div style="display:flex;gap:0.5rem;">
                        <a href="#" style="color:#fff;"><i class="fab fa-linkedin-in"></i></a>
                        <a href="#" style="color:#fff;"><i class="fab fa-github"></i></a>
                        <a href="#" style="color:#fff;"><i class="fas fa-envelope"></i></a>
                    </div>
                </div>
                <!-- Membre 5 (correction du nom) -->
                <div style="display:flex;flex-direction:column;align-items:center;background:none;box-shadow:none;padding:0;">
                    <img src="https://randomuser.me/api/portraits/men/12.jpg" alt="ADECHI Aladé" style="width:70px;height:70px;border-radius:50%;object-fit:cover;margin-bottom:0.7rem;border:3px solid #00d1ff;">
                    <span style="display:block;font-size:1.05rem;color:#fff;font-weight:600;margin-bottom:0.2rem;white-space:nowrap;">ADECHI Aladé</span>
                    <p style="margin:0 0 0.5rem 0;font-size:0.93rem;color:#00d1ff;">Pôle IT</p>
                    <div style="display:flex;gap:0.5rem;">
                        <a href="#" style="color:#fff;"><i class="fab fa-linkedin-in"></i></a>
                        <a href="#" style="color:#fff;"><i class="fab fa-github"></i></a>
                        <a href="#" style="color:#fff;"><i class="fas fa-envelope"></i></a>
                    </div>
                </div>
                <!-- Membre 6 -->
                <div style="display:flex;flex-direction:column;align-items:center;background:none;box-shadow:none;padding:0;">
                    <img src="https://randomuser.me/api/portraits/women/33.jpg" alt="SALIFOU Fatihatou" style="width:70px;height:70px;border-radius:50%;object-fit:cover;margin-bottom:0.7rem;border:3px solid #00d1ff;">
                    <span style="display:block;font-size:1.05rem;color:#fff;font-weight:600;margin-bottom:0.2rem;white-space:nowrap;">SALIFOU Fatihatou</span>
                    <p style="margin:0 0 0.5rem 0;font-size:0.93rem;color:#00d1ff;">Pôle Mécanique</p>
                    <div style="display:flex;gap:0.5rem;">
                        <a href="#" style="color:#fff;"><i class="fab fa-linkedin-in"></i></a>
                        <a href="#" style="color:#fff;"><i class="fab fa-github"></i></a>
                        <a href="#" style="color:#fff;"><i class="fas fa-envelope"></i></a>
                    </div>
                </div>
                <!-- Membre 7 -->
                <div style="display:flex;flex-direction:column;align-items:center;background:none;box-shadow:none;padding:0;">
                    <img src="https://randomuser.me/api/portraits/women/55.jpg" alt="FAGBITE Rachelle" style="width:70px;height:70px;border-radius:50%;object-fit:cover;margin-bottom:0.7rem;border:3px solid #00d1ff;">
                    <span style="display:block;font-size:1.05rem;color:#fff;font-weight:600;margin-bottom:0.2rem;white-space:nowrap;">FAGBITE Rachelle</span>
                    <p style="margin:0 0 0.5rem 0;font-size:0.93rem;color:#00d1ff;">Pôle Mécanique</p>
                    <div style="display:flex;gap:0.5rem;">
                        <a href="#" style="color:#fff;"><i class="fab fa-linkedin-in"></i></a>
                        <a href="#" style="color:#fff;"><i class="fab fa-github"></i></a>
                        <a href="#" style="color:#fff;"><i class="fas fa-envelope"></i></a>
                    </div>
                </div>
                <!-- Membre 8 -->
                <div style="display:flex;flex-direction:column;align-items:center;background:none;box-shadow:none;padding:0;">
                    <img src="https://randomuser.me/api/portraits/men/77.jpg" alt="DEGUENON David" style="width:70px;height:70px;border-radius:50%;object-fit:cover;margin-bottom:0.7rem;border:3px solid #00d1ff;">
                    <span style="display:block;font-size:1.05rem;color:#fff;font-weight:600;margin-bottom:0.2rem;white-space:nowrap;">DEGUENON David</span>
                    <p style="margin:0 0 0.5rem 0;font-size:0.93rem;color:#00d1ff;">Pôle Mécanique</p>
                    <div style="display:flex;gap:0.5rem;">
                        <a href="#" style="color:#fff;"><i class="fab fa-linkedin-in"></i></a>
                        <a href="#" style="color:#fff;"><i class="fab fa-github"></i></a>
                        <a href="#" style="color:#fff;"><i class="fas fa-envelope"></i></a>
                    </div>
                </div>
                <!-- Membre 9 -->
                <div style="display:flex;flex-direction:column;align-items:center;background:none;box-shadow:none;padding:0;">
                    <img src="https://randomuser.me/api/portraits/men/99.jpg" alt="HOUNNOUVI Hermes" style="width:70px;height:70px;border-radius:50%;object-fit:cover;margin-bottom:0.7rem;border:3px solid #00d1ff;">
                    <span style="display:block;font-size:1.05rem;color:#fff;font-weight:600;margin-bottom:0.2rem;white-space:nowrap;">NOUVEAU MEMBRE</span>
                    <p style="margin:0 0 0.5rem 0;font-size:0.93rem;color:#00d1ff;">Pôle Electronique</p>
                    <div style="display:flex;gap:0.5rem;">
                        <a href="#" style="color:#fff;"><i class="fab fa-linkedin-in"></i></a>
                        <a href="#" style="color:#fff;"><i class="fab fa-github"></i></a>
                        <a href="#" style="color:#fff;"><i class="fas fa-envelope"></i></a>
                    </div>
                </div>
                <!-- Membre 10 -->
                <div style="display:flex;flex-direction:column;align-items:center;background:none;box-shadow:none;padding:0;">
                    <img src="https://randomuser.me/api/portraits/women/99.jpg" alt="ADAHE Christelle" style="width:70px;height:70px;border-radius:50%;object-fit:cover;margin-bottom:0.7rem;border:3px solid #00d1ff;">
                    <span style="display:block;font-size:1.05rem;color:#fff;font-weight:600;margin-bottom:0.2rem;white-space:nowrap;">NOUVELLE MEMBRE</span>
                    <p style="margin:0 0 0.5rem 0;font-size:0.93rem;color:#00d1ff;">Pôle Electronique</p>
                    <div style="display:flex;gap:0.5rem;">
                        <a href="#" style="color:#fff;"><i class="fab fa-linkedin-in"></i></a>
                        <a href="#" style="color:#fff;"><i class="fab fa-github"></i></a>
                        <a href="#" style="color:#fff;"><i class="fas fa-envelope"></i></a>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <!-- Section Contact avec cadres séparés à droite, largeur égale -->
    <section class="section" id="contact">
        <div class="section-container" style="max-width:1200px;margin:0 auto;">
            <div class="section-title">
                <h2 class="cyber-title">Contact</h2>
                <p>Pour toute question ou prise de contact, utilisez le formulaire ou les coordonnées ci-dessous.</p>
            </div>
            <div class="contact-flex" style="display:flex;align-items:stretch;gap:3rem;flex-wrap:wrap;">
                <!-- Carte à gauche, encadrée et alignée -->
                <div class="contact-media contact-align" style="flex:1 1 480px;min-width:340px;max-width:600px;display:flex;flex-direction:column;justify-content:stretch;">
                    <div class="contact-card" style="background:rgba(10,25,47,0.92);border-radius:18px;box-shadow:0 4px 32px #00d1ff33;padding:1.5rem;height:100%;display:flex;flex-direction:column;align-items:center;justify-content:flex-start;">
                        <h3 style="color:#00f7ff;margin-bottom:1rem;">Localisation</h3>
                        <iframe src="https://www.google.com/maps?q=Université+Catholique+de+l'Afrique+de+l'Ouest,+Cotonou,+Bénin&output=embed" width="100%" height="380" style="border:0;border-radius:12px;min-height:320px;max-width:100%;flex:1;" allowfullscreen="" loading="lazy" referrerpolicy="no-referrer-when-downgrade"></iframe>
                    </div>
                </div>
                <!-- Deux cadres séparés à droite, largeur égale à gauche -->
                <div style="flex:1 1 480px;min-width:340px;max-width:600px;display:flex;flex-direction:column;gap:2rem;justify-content:stretch;">
                    <div class="contact-card" style="background:rgba(10,25,47,0.92);border-radius:18px;box-shadow:0 4px 32px #00d1ff33;padding:1.5rem;display:flex;flex-direction:column;justify-content:flex-start;">
                        <h3 style="color:#00f7ff;margin-bottom:0.7rem;">Coordonnées</h3>
                        <div style="margin-bottom:1rem;display:flex;align-items:center;">
                            <i class="fas fa-phone" style="color:#00d1ff;margin-right:1rem;"></i>
                            <span><strong>Téléphone :</strong> +229 01 55 60 7630</span>
                        </div>
                        <div style="margin-bottom:1rem;display:flex;align-items:center;">
                            <i class="fas fa-envelope" style="color:#00d1ff;margin-right:1rem;"></i>
                            <span><strong>Email :</strong> <a href="mailto:contact@tekbot.io" style="color:#00d1ff;text-decoration:underline;">contact@tekbot.io</a></span>
                        </div>
                    </div>
                    <div class="contact-card" style="background:rgba(10,25,47,0.92);border-radius:18px;box-shadow:0 4px 32px #00d1ff33;padding:1.5rem;display:flex;flex-direction:column;justify-content:flex-start;">
                        <h3 style="color:#00f7ff;margin-bottom:1rem;">Envoyer un message</h3>
                        <form action="mailto:contact@tekbot.io" method="POST" enctype="text/plain" style="flex:1;display:flex;flex-direction:column;justify-content:flex-start;">
                            <input type="text" name="Nom" placeholder="Votre nom" required style="width:100%;padding:0.7rem;margin-bottom:0.7rem;border-radius:4px;border:none;">
                            <input type="email" name="Email" placeholder="Votre email" required style="width:100%;padding:0.7rem;margin-bottom:0.7rem;border-radius:4px;border:none;">
                            <input type="text" name="Objet" placeholder="Objet du message" style="width:100%;padding:0.7rem;margin-bottom:0.7rem;border-radius:4px;border:none;">
                            <textarea name="Message" placeholder="Votre message..." required style="width:100%;padding:0.7rem;margin-bottom:0.7rem;border-radius:4px;border:none;min-height:80px;"></textarea>
                            <button type="submit" class="btn btn-primary" style="width:100%;">Envoyer</button>
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </section>
    <style>
@media (min-width: 900px) {
    .contact-flex {align-items:stretch;}
    .contact-align {display:flex;flex-direction:column;justify-content:stretch;}
    .contact-card {width:100%;box-sizing:border-box;}
}
@media (max-width: 1050px) {
    .contact-flex { flex-direction: column !important; gap: 2rem !important; }
    .contact-align, .contact-card { min-width: 0 !important; max-width: 100% !important; height:auto !important; }
}
</style>

    <!-- Section Documentation -->
    <section class="section" id="documentation">
        <div class="section-container">
            <div class="section-title">
                <h2 class="cyber-title">Documentation</h2>
                <p>Accédez à la documentation complète de chaque domaine du projet TRC 2025 :</p>
            </div>
            <div class="features-grid">
                <div class="feature-card holographic-card">
                    <h3>Informatique</h3>
                    <a href="programmation.html" class="btn btn-primary">Voir la documentation</a>
                </div>
                <div class="feature-card holographic-card">
                    <h3>Électronique</h3>
                    <a href="electronique.html" class="btn btn-primary">Voir la documentation</a>
                </div>
                <div class="feature-card holographic-card">
                    <h3>Mécanique</h3>
                    <a href="mecanique.html" class="btn btn-primary">Voir la documentation</a>
                </div>
            </div>
        </div>
    </section>

    <!-- Footer moderne, marges et espaces réduits -->
    <footer style="background: linear-gradient(120deg, #0a192f 60%, #001a2e 100%); color: #e6f1ff; padding: 1.2rem 0 0.5rem 0; border-top: 2px solid #00d1ff22;">
        <div class="footer-grid" style="max-width: 1250px; margin: 0 auto; display: flex; flex-wrap: wrap; align-items: flex-start; justify-content: space-between; gap: 1.2rem;">
            <!-- À propos à gauche -->
            <div style="flex:2 1 350px; min-width:220px;display:flex;flex-direction:column;align-items:flex-start;gap:0.5rem;">
                <div style="font-weight:700; color:#00d1ff; font-size:1.05rem;letter-spacing:1px;text-transform:uppercase;">À propos</div>
                <div style="font-size:0.98rem;opacity:0.85;line-height:1.4;text-align:left;">
                    UCAO-TECH, c’est une équipe d’innovation et de passionnés de robotique engagés pour l’excellence au TRC 2025. Notre mission : former, innover et propulser la technologie au service de la jeunesse africaine. Suivez nos projets, nos valeurs et notre actualité sur ce site.
                </div>
                <img src="https://ucaotech.com/wp-content/uploads/2024/10/UCAO-TECH-1.png" alt="UCAO-TECH Logo" style="height: 28px; margin-top:0.3rem;">
            </div>
            <!-- Liens rapides au centre -->
            <div style="flex:1 1 220px; min-width:200px;display:flex;flex-direction:column;align-items:flex-start;gap:0.5rem;">
                <div style="font-weight:700; color:#00d1ff; font-size:1.05rem;letter-spacing:1px;text-transform:uppercase;">Liens rapides</div>
                <ul style="list-style:none;padding:0;margin:0;line-height:1.5;">
                    <li><a href="#accueil" style="color: #e6f1ff; text-decoration: none;transition:color 0.2s;" onmouseover="this.style.color='#00d1ff'" onmouseout="this.style.color='#e6f1ff'">Accueil</a></li>
                    <li><a href="#a-propos" style="color: #e6f1ff; text-decoration: none;transition:color 0.2s;" onmouseover="this.style.color='#00d1ff'" onmouseout="this.style.color='#e6f1ff'">À propos</a></li>
                    <li><a href="#equipe" style="color: #e6f1ff; text-decoration: none;transition:color 0.2s;" onmouseover="this.style.color='#00d1ff'" onmouseout="this.style.color='#e6f1ff'">Équipe</a></li>
                    <li><a href="#contact" style="color: #e6f1ff; text-decoration: none;transition:color 0.2s;" onmouseover="this.style.color='#00d1ff'" onmouseout="this.style.color='#e6f1ff'">Contact</a></li>
                    <li><a href="#documentation" style="color: #e6f1ff; text-decoration: none;transition:color 0.2s;" onmouseover="this.style.color='#00d1ff'" onmouseout="this.style.color='#e6f1ff'">Documentation</a></li>
                </ul>
            </div>
            <!-- Contacts à droite -->
            <div style="flex:1 1 220px; min-width:200px;display:flex;flex-direction:column;align-items:flex-start;gap:0.5rem;">
                <div style="font-weight:700; color:#00d1ff; font-size:1.05rem;letter-spacing:1px;text-transform:uppercase;">Contacts</div>
                <div style="margin-bottom:0.3rem;display:flex;align-items:center;">
                    <i class="fas fa-phone" style="color:#00d1ff;margin-right:0.7rem;"></i>
                    <span>+229 01 55 60 7630</span>
                </div>
                <div style="margin-bottom:0.3rem;display:flex;align-items:center;">
                    <i class="fas fa-envelope" style="color:#00d1ff;margin-right:0.7rem;"></i>
                    <span><a href="mailto:contact@tekbot.io" style="color:#e6f1ff;text-decoration:underline;">contact@tekbot.io</a></span>
                </div>
                <div style="display: flex; gap: 0.5rem; margin-top:0.5rem;">
                    <a href="#" style="color:#00d1ff;font-size:1.05rem;"><i class="fab fa-facebook-f"></i></a>
                    <a href="#" style="color:#00d1ff;font-size:1.05rem;"><i class="fab fa-twitter"></i></a>
                    <a href="#" style="color:#00d1ff;font-size:1.05rem;"><i class="fab fa-instagram"></i></a>
                    <a href="#" style="color:#00d1ff;font-size:1.05rem;"><i class="fab fa-linkedin-in"></i></a>
                    <a href="#" style="color:#00d1ff;font-size:1.05rem;"><i class="fab fa-github"></i></a>
                </div>
                <form style="margin-top:0.3rem;display:flex;flex-direction:column;gap:0.2rem;">
                    <div style="font-size:0.93rem;opacity:0.8;line-height:1.1;">Recevez nos actus :</div>
                    <div style="display:flex;gap:0.3rem;">
                        <input id="newsletter" type="email" placeholder="Votre email" style="flex:1;padding:0.3rem 0.6rem;border-radius:4px;border:none;">
                        <button type="submit" style="background:#00d1ff;color:#09121e;border:none;border-radius:4px;padding:0.3rem 0.7rem;font-weight:600;cursor:pointer;">OK</button>
                    </div>
                </form>
            </div>
        </div>
        <div style="text-align:center;font-size:0.91rem;opacity:0.6;margin-top:0.7rem;">
            &copy; 2025 UCAO-TECH – Tous droits réservés
        </div>
    </footer>
    <!-- Réduction de la largeur des cartes membres et centrage du contenu -->
    <style>
.member-card.holographic-card {
    max-width: 200px !important;
    min-width: 150px !important;
    margin: 0.7rem auto !important;
    padding: 0.7rem 0.5rem 0.7rem 0.5rem !important;
    display: flex !important;
    flex-direction: column !important;
    align-items: center !important;
    box-shadow: 0 2px 12px #00d1ff22 !important;
    height: auto !important;
}
.member-image {
    margin-bottom: 0.3rem !important;
}
.member-image img {
    max-width: 60px !important;
    height: 60px !important;
    border-radius: 50%;
    object-fit: cover;
    margin: 0 auto;
    display: block;
}
.member-info {
    text-align: center;
    margin: 0 !important;
    padding: 0 !important;
}
.member-info h3 {
    margin: 0.2rem 0 0.1rem 0 !important;
    font-size: 1.05rem !important;
}
.member-info p {
    margin: 0 0 0.2rem  0 !important;
    font-size: 0.93rem !important;
}
.social-links {
    margin: 0.1rem 0 0 0 !important;
    gap: 0.3rem !important;
}
.social-links a {
    font-size: 1.05rem !important;
}
</style>

    <!-- Back to Top Button -->
    <div class="back-to-top">
        <i class="fas fa-arrow-up"></i>
    </div>

    <!-- JavaScript -->
    <script>
        // Mobile Menu Toggle
        const mobileMenuBtn = document.querySelector('.mobile-menu-btn');
        const navLinks = document.querySelector('.nav-links');
        
        mobileMenuBtn.addEventListener('click', () => {
            navLinks.classList.toggle('active');
            mobileMenuBtn.innerHTML = navLinks.classList.contains('active') ? 
                '<i class="fas fa-times"></i>' : '<i class="fas fa-bars"></i>';
        });
        
        // Close mobile menu when clicking on a link
        document.querySelectorAll('.nav-links a').forEach(link => {
            link.addEventListener('click', () => {
                navLinks.classList.remove('active');
                mobileMenuBtn.innerHTML = '<i class="fas fa-bars"></i>';
            });
        });
        
        // Set active link based on current page
        const currentPage = window.location.pathname.split('/').pop() || 'index.html';
        document.querySelectorAll('.nav-links a').forEach(link => {
            if (link.getAttribute('href') === currentPage) {
                link.classList.add('active');
            } else {
                link.classList.remove('active');
            }
        });
        
        // Smooth Scrolling for Anchor Links
        document.querySelectorAll('a[href^="#"]').forEach(anchor => {
            anchor.addEventListener('click', function(e) {

                e.preventDefault();
                
                const target = document.querySelector(this.getAttribute('href'));
                if(target) {
                    window.scrollTo({
                        top: target.offsetTop - 80,
                        behavior: 'smooth'
                    });
                }
            });
        });
        
        // Back to Top Button
        const backToTopBtn = document.querySelector('.back-to-top');
        
        window.addEventListener('scroll', () => {
            if(window.pageYOffset > 300) {
                backToTopBtn.classList.add('active');
            } else {
                backToTopBtn.classList.remove('active');
            }
        });
        
        backToTopBtn.addEventListener('click', () => {
            window.scrollTo({
                top: 0,
                behavior: 'smooth'
            });
        });
        
        // Animate elements when they come into view
        const animateOnScroll = () => {
            const elements = document.querySelectorAll('.section, .feature-card, .member-card, .progress-step');
            
            elements.forEach(element => {
                const elementPosition = element.getBoundingClientRect().top;
                const windowHeight = window.innerHeight;
                
                if(elementPosition < windowHeight - 100) {
                    element.style.opacity = '1';
                    element.style.transform = 'translateY(0)';
                }
            });
        };
        
        // Set initial state for animation
        document.querySelectorAll('.section, .feature-card, .member-card, .progress-step').forEach(element => {
            element.style.opacity = '0';
            element.style.transform = 'translateY(30px)';
            element.style.transition = 'opacity 0.6s ease, transform 0.6s ease';
        });
        
        window.addEventListener('scroll', animateOnScroll);
        window.addEventListener('load', animateOnScroll);
        
        // Circuit board animation
        const paths = document.querySelectorAll('.circuit-path');
        paths.forEach((path, index) => {
            const length = path.getTotalLength();
            path.style.strokeDasharray = length;
            path.style.strokeDashoffset = length;
            path.style.animation = `dash ${10 + index * 2}s linear infinite`;
        });
        
        // Glitch effect on hero title
        const glitchEffect = document.querySelector('.glitch-effect');
        setInterval(() => {
            glitchEffect.style.animation = 'none';
            void glitchEffect.offsetWidth; // Trigger reflow
            glitchEffect.style.animation = 'glitch 2s infinite';
        }, 8000);
    </script>
</body>
</html>
