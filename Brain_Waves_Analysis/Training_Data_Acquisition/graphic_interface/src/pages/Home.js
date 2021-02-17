import React from 'react';

import "./home.css";

import Card from "../components/Card.js";

class Home extends React.Component {

	render() {
		return (
			<React.Fragment>
				<header className="home-header">
					<h1>Cerebro</h1>
					<h2>Training Data Acquisition</h2>
				</header>
				
				<Footer/>
			</React.Fragment>
		);
	}
}

export default Home;