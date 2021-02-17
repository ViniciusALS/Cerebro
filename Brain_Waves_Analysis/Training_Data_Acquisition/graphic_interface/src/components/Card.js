import React from 'react';

import "./card.css";

class Card extends React.Component {

	constructor(props) {
		super(props);
		this.state = {
			classNames: "card " + props.className
		};
	}

	render() {
		return (
			<div className={this.state.classNames}>
				{this.props.children}
			</div>
		);
	}
}

export default Card;